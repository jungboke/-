import java.io.*;
import java.util.*;

public class Main {

    static Boolean check_T(List<Integer> temp) {
        if(temp.get(2)>=temp.get(0)+temp.get(1)) return false;
        else return true;
    }

    static Boolean check_E(List<Integer> temp) {
        if((temp.get(0).equals(temp.get(1)))&&(temp.get(1).equals(temp.get(2)))) return true;
        else return false;
    }

    static Boolean check_I(List<Integer> temp) {
        if((temp.get(0).equals(temp.get(1)))||(temp.get(1).equals(temp.get(2)))||(temp.get(0).equals(temp.get(2)))) return true;
        else return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            if(x==0&&y==0&&z==0) break;
            List<Integer> temp = new ArrayList<>();
            temp.add(x);
            temp.add(y);
            temp.add(z);
            Collections.sort(temp);
            if(!check_T(temp)) sb.append("Invalid").append("\n");
            else if(check_E(temp)) sb.append("Equilateral").append("\n");
            else if(check_I(temp)) sb.append("Isosceles").append("\n");
            else sb.append("Scalene").append("\n");
        }
        System.out.println(sb.toString());
    }
}

