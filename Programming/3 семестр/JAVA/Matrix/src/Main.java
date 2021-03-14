import java.util.*;
import java.util.Scanner;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        matr ob=new matr();
        Random rnd = new Random(System.currentTimeMillis());
        Scanner in = new Scanner(System.in);
        System.out.println("Введите порядок матрицы(желательно>5,для лучшей генерации матрицы): ");
        int n = in.nextInt();

        int[][] matrix = new int[n][n];
        System.out.println("Матрица: ");
        for (int row = 0; row < n-1; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = (-n) + rnd.nextInt((2 * n) + 1);
            }
        }
        for(int col=0;col<n;col++)
        {
            matrix[n-1][col]=0;
            matrix[n-5][col]=0;
        }
        for(int row=0;row<n;row++)
        {
            matrix[row][n-4]=0;
            matrix[row][n-2]=0;
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                System.out.print(matrix[row][col]);
                System.out.print("\t");
            }
            System.out.println();
        }
        /*for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                matrix[col][row] = (-n) + rnd.nextInt((2 * n) + 1);
                System.out.print(matrix[col][row]);
                System.out.print("\t");
            }
            System.out.println();
        }*/
        matrix=ob.delete(matrix,n);
        int row_length=matrix.length-2;
        int col_length=matrix[0].length-1;

        System.out.println("Искомая матрица:");
        for (int row = 0; row < row_length; row++) {
            for (int col = 0; col < col_length; col++) {
                System.out.print(matrix[row][col]);
                System.out.print("\t");
            }
            System.out.println();
        }

    }
}
