import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static class FastReader {
        BufferedReader b;
        StringTokenizer s; 
        public FastReader() {
            b = new BufferedReader
              (new InputStreamReader(System.in));
        }
        String next() {
            while (s == null || !s.hasMoreElements()) {
                try {
                    s = new StringTokenizer(b.readLine());
                } catch (IOException e) {
                    e.printStackTrace(); 
                }
            }
            return s.nextToken();
        }
        int nextInt() { 
            return Integer.parseInt(next()); 
        }
        long nextLong() { 
            return Long.parseLong(next()); 
        }
        double nextDouble() { 
            return Double.parseDouble(next()); 
        }
        String nextLine() {
            String str = "";
            try {
                if (s.hasMoreTokens()) {
                    str = s.nextToken("\n");
                } else {
                    str = b.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace(); 
            }
            return str;
        }
    }


		static boolean[] good = new boolean[26];
		static char[] pattern, query;

		static boolean match(char p, char q) {
				if (p == '*') return false;
				if (p == '?') return good[q-'a'];
				return p == q;
		}

		static boolean ok(int pl, int pr, int ql, int qr) {
				while (pl <= pr && ql <= qr && match(pattern[pl], query[ql])) {
					pl++; ql++;
				}
				if (pl > pr && ql > qr) return true; 
				while (pr >= pl && qr >= ql && match(pattern[pr], query[qr])) {
					pr--; qr--;
				}
				if (pl != pr || pattern[pl] != '*') return false;
				while (ql <= qr) {
					if (good[query[ql]-'a']) return false;
					ql++;
				}
				return true;
		}

		public static void main(String[] args) {
			FastReader fr = new FastReader();
			String goodString = fr.next();

			for (char ch: goodString.toCharArray()) {
				good[ch-'a'] = true;
			}

			pattern = fr.next().toCharArray();

			int pl = pattern.length;
			int n = fr.nextInt();
			while(n-- > 0) {
				String ans = "NO";
				query = fr.next().toCharArray();
				int ql = query.length;
				if (ok(0, pl-1, 0, ql-1)) {
					ans = "YES";
				}
				System.out.println(ans);
			}
		}
}
