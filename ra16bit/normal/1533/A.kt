import java.util.*
import java.io.*

class IOStream {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st: StringTokenizer? = null

    fun nextToken(): String? {
        while (st == null || !st!!.hasMoreTokens())
            st = StringTokenizer(br.readLine())
        return st!!.nextToken()
    }

    fun nextInt(): Int {
        return nextToken()!!.toInt()
    }

    fun nextLong(): Long {
        return nextToken()!!.toLong()
    }
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt();
        val k = inp.nextInt();
        var r = 0
        for (i in 0..n-1) {
            val x = inp.nextInt();
            val y = inp.nextInt();
            if (x<=k) r = Math.max(r, y-k+1)
        }
        out.println(r);
    }
    out.close();
}