import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.StringTokenizer

class Program {
    class FastReader {
        private val b = BufferedReader(InputStreamReader(System.`in`))
        private var s: StringTokenizer? = null

        fun next(): String {
            while (s == null || !s!!.hasMoreElements()) {
                try {
                    s = StringTokenizer(b.readLine())
                } catch (e: IOException) {
                    e.printStackTrace()
                }
            }
            return s!!.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        fun nextLong(): Long {
            return next().toLong()
        }

        fun nextDouble(): Double {
            return next().toDouble()
        }

        fun nextLine(): String {
            return try {
                if (s!!.hasMoreTokens()) {
                    s!!.nextToken("\n")
                } else {
                    b.readLine()
                }
            } catch (e: IOException) {
                e.printStackTrace()
                ""
            }
        }
    }

    private val good = BooleanArray(26)
    private lateinit var pattern: CharArray
    private lateinit var query: CharArray

    private fun match(p: Char, q: Char): Boolean {
        return when {
            p == '*' -> false
            p == '?' -> good[q - 'a']
            else -> p == q
        }
    }

    private fun ok(_pl: Int, _pr: Int, _ql: Int, _qr: Int): Boolean {
        var pl = _pl
        var pr = _pr
        var ql = _ql
        var qr = _qr

        while (pl <= pr && ql <= qr && match(pattern[pl], query[ql])) {
            pl++
            ql++
        }
        if (pl > pr && ql > qr) return true
        while (pr >= pl && qr >= ql && match(pattern[pr], query[qr])) {
            pr--
            qr--
        }
        if (pl != pr || pattern[pl] != '*') return false
        while (ql <= qr) {
            if (good[query[ql] - 'a']) return false
            ql++
        }
        return true
    }

    fun main() {
        val fr = FastReader()
        val goodString = fr.next()

        for (ch in goodString.toCharArray()) {
            good[ch - 'a'] = true
        }

        pattern = fr.next().toCharArray()

        val pl = pattern.size
        var n = fr.nextInt()
        while (n-- > 0) {
            var ans = "NO"
            query = fr.next().toCharArray()
            val ql = query.size
            if (ok(0, pl - 1, 0, ql - 1)) {
                ans = "YES"
            }
            println(ans)
        }
    }
}

fun main() {
  val program = Program()
  program.main()
}


