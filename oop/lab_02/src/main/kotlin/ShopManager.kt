class ShopManager {
    private var _shopList: MutableMap<Int, Shop> = mutableMapOf()
    private var _productList: MutableMap<Int, Product> = mutableMapOf()

    fun createShop(id: Int, name: String, adress: String) {
        if (_shopList.containsKey(id)) throw SameIdEntityException(id)
        _shopList[id] = Shop(id, name, adress)
    }
    fun createProduct(id: Int, name: String) {
        if (_productList.containsKey(id)) throw SameIdEntityException(id)
        _productList[id] = Product(id, name)
    }
    fun newBatch(shopId: Int, productName: String, amount: Int, cost: Int) {
        val productId = specifyProduct(productName)
        if (!_shopList.containsKey(shopId)) throw UnknownEntityException(shopId.toString())
        if (!_productList.containsKey(productId)) throw UnknownEntityException(productId.toString())
        _shopList[shopId]?.newBatch(productId, amount, cost)
    }
    fun whereIsCheaperShopName(productName: String): String {
        val productId = specifyProduct(productName)
        var leastCost = -1
        lateinit var tempShop: Shop
        for (shop in _shopList.values) {
            val tempCost = shop.getProductCost(productId)
            if (tempCost != -1) {
                if (tempCost < leastCost || leastCost == -1) {
                    leastCost = tempCost
                    tempShop = shop
                }
            }
        }
        return if (leastCost == -1) "Товар не продается"
        else tempShop.name
    }
    fun whereIsCheaperShopId(productName: String): Int {
        val productId = specifyProduct(productName)
        var leastCost = -1
        lateinit var tempShop: Shop
        for (shop in _shopList.values) {
            val tempCost = shop.getProductCost(productId)
            if (tempCost != -1) {
                if (tempCost < leastCost || leastCost == -1) {
                    leastCost = tempCost
                    tempShop = shop
                }
            }
        }
        return if (leastCost == -1) -1
        else tempShop.getCode()
    }
    private fun checkCost(shopId: Int, productsAndAmount: MutableList<Pair<Int, Int>>): Int {
        if (!_shopList.containsKey(shopId)) throw UnknownEntityException(shopId.toString())
        for (pair in productsAndAmount) {
            if (!_productList.containsKey(pair.first)) throw UnknownEntityException(pair.first.toString())
        }
        return _shopList[shopId]!!.checkCost(productsAndAmount)
    }
    fun buy(shopId: Int, productsAndAmount: MutableList<Pair<Int, Int>>): String {
        if (!_shopList.containsKey(shopId)) throw UnknownEntityException(shopId.toString())
        for (pair in productsAndAmount) {
            if (!_productList.containsKey(pair.first)) throw UnknownEntityException(pair.first.toString())
        }
        return "Совершена покупка на ${_shopList[shopId]!!.buy(productsAndAmount)}"
    }
    fun buyProfitable(productsAndAmount: MutableList<Pair<Int, Int>>): String {
        var leastCheck = -1
        lateinit var leastCheckShop: Shop
        for (shop in _shopList.values) {
            val check = checkCost(shop.getCode(), productsAndAmount)
            if (check == -1) continue
            if (check < leastCheck || leastCheck == -1) {
                leastCheck = check
                leastCheckShop = shop
            }
        }
        if (leastCheck == -1) throw UnableToBuyException()
        return buy(leastCheckShop.getCode(), productsAndAmount) + " в магазине " +
                leastCheckShop.getCode().toString() + " - " + leastCheckShop.name
    }
    fun whatCanIBuy(shopId: Int, cash: Int): MutableList<Pair<Int, Int>> {
        if (!_shopList.containsKey(shopId)) throw UnknownEntityException(shopId.toString())
        return _shopList[shopId]!!.whatCanIBuy(cash)
    }
    private fun specifyProduct(productName: String): Int {
        val matchedProducts: MutableList<Product> = mutableListOf()
        for (product in _productList.values) {
            if (product.name == productName) matchedProducts.add(product)
        }
        when {
            matchedProducts.size > 1 -> {
                for (product in matchedProducts) {
                    println(product.getCode())
                }
                println("Много совпадений по имени товара. Выберите конкретный товар: ")
                var id = readLine()!!.toInt()
                while (true) {
                    for (temp_id in matchedProducts) {
                        if (temp_id.getCode() == id) return id
                    }
                    println("Введен неверный id. Повторите ввод:")
                    id = readLine()!!.toInt()
                }
            }
            matchedProducts.size == 1 -> return matchedProducts[0].getCode()
            else -> throw UnknownEntityException(productName)
        }
    }
}