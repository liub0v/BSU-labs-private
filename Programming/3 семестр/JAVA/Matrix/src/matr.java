public class matr {

    int[][] delete(int[][] matrix, int n) {
        int temp, i, j, y, m;
        m = n;
        for (i = 0; i < n; i++) {
            temp = 0;
            for (j = 0; j < m; j++)
                if (matrix[i][j] != 0)
                    temp = 1;
            if (temp == 0) {
                for (y = i; y < n - 1; y++)
                    for (j = 0; j < m; j++)
                        matrix[y][j] = matrix[y + 1][j];
                n--;
                i--;
            }
        }
        for (i = 0; i < m; i++) {
            temp = 0;
            for (j = 0; j < n; j++)
                if (matrix[j][i] != 0)
                    temp = 1;
            if (temp == 0) {
                for (y = i; y < m - 1; y++)
                    for (j = 0; j < n; j++)
                        matrix[j][y] = matrix[j][y + 1];
                m--;
                j--;
            }
        }
        return matrix;
    }
}





