class Shop(shopCode: Int, shopName: String, shopAddress: String) {
    private var _code: Int = shopCode
    // <id товара, <Количество, Цена>>
    private var _products: MutableMap<Int, Pair<Int, Int>> = mutableMapOf()
    var adress: String = shopAddress
    var name: String = shopName

    fun getCode(): Int {
        return  _code
    }
    fun newBatch(productId: Int, amount: Int, cost: Int) {
        if (!_products.containsKey(productId)) {
            _products[productId] = Pair(amount, cost)
            return
        }
        var tempAmount = _products[productId]!!.first
        tempAmount += amount
        _products[productId] = Pair(tempAmount, cost)
    }
    fun getProductCost(id: Int): Int {
        return if (!_products.containsKey(id)) -1
        else _products[id]!!.second
    }
    fun whatCanIBuy(cash: Int): MutableList<Pair<Int, Int>> {
        val tempList: MutableList<Pair<Int, Int>> = mutableListOf()
        for (product in _products.entries) {
            var amount = cash / product.value.second
            if (amount > product.value.first) {
                amount = product.value.first
            }
            tempList.add(Pair(product.key, amount))
        }
        return tempList
    }
    fun checkCost(productsAndAmount: MutableList<Pair<Int, Int>>): Int {
        var check = 0
        for (pair in productsAndAmount) {
            if (!_products.containsKey(pair.first)) return -1
            if (_products[pair.first]!!.first < pair.second) return -1
            check += _products[pair.first]!!.second * pair.second
        }
        return check
    }
    fun buy(productsAndAmount: MutableList<Pair<Int, Int>>): Int {
        val check = checkCost(productsAndAmount)
        if (check == -1) throw UnableToBuyException()
        for (pair in productsAndAmount) {
            val tempAmount = _products[pair.first]!!.first - pair.second
            _products[pair.first] = Pair(tempAmount, _products[pair.first]!!.second)
        }
        return check
    }
}