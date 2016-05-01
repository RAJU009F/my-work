import java.io.*;
import java.util.*;

public class SaplingTreeHeight {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        int H ;
        while(T>0)
        {
               H = 1;
            int N = sc.nextInt();
            for(int i=0; i<N;i++)   
                {
                if(i%2==0)
                    H *=2;
                else
                    H +=1;
                
            }
            
            System.out.println(H);
            T--;
        }
        
    }
}