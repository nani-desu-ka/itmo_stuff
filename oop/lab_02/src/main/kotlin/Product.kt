class Product(productCode: Int, productName: String) {
    private var _code: Int = productCode
    var name: String = productName

    fun getCode(): Int {
        return _code
    }
}