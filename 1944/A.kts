fun main() {
  val tc = readln().toInt()
  (1..tc).forEach {
    val (n,k) = readln().split(' ').map{it.toInt()}
    val ans = if (k >= n-1) 1 else n
    println(ans)
  }
}

main()
