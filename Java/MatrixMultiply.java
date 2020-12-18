import java.util.Scanner;

public class MatrixMultiply {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Input A Length: ");
		int sizeOne = scan.nextInt();

		while (sizeOne < 0) {
			sizeOne = scan.nextInt();
		}

		System.out.printf("Input A Second Length: ");
		int sizeTwo = scan.nextInt();

		while (sizeTwo < 0) {
			sizeTwo = scan.nextInt();
		}

		int[][] matrixA = randomArray2D(sizeOne, sizeTwo);
		int[][] matrixB = randomArray2D(sizeTwo, sizeOne);

		int[][] matrixC = multipyArray(matrixA, matrixB);

		displayMatrix(matrixC);
		scan.close();
	}

	public static int[][] randomArray2D(int a, int b) {
		int[][] matrix = new int[a][b];

		for (int r = 0; r < a; r++) {
			for (int c = 0; c < b; c++) {
				matrix[r][c] = (int) ((Math.random() * 10) + 1);
			}
		}

		return matrix;
	}

	public static int[][] multipyArray(int[][] matrixA, int[][] matrixB) {
		int[][] finalMatrix = new int[matrixA.length][matrixA.length];
		for (int r = 0; r < matrixA.length; r++) {
			for (int c = 0; c < matrixA.length; c++) {
				for (int i = 0; i < matrixB.length; i++) {
					finalMatrix[r][c] = (finalMatrix[r][c] + (matrixA[r][i] * matrixB[i][c]));
				}
			}
		}
		return finalMatrix;

	}

	public static void displayMatrix(int[][] matrix) {
		for (int r = 0; r < matrix.length; r++) {
			for (int c = 0; c <= matrix[0].length - 1; c++) {
				System.out.printf("%-8d", matrix[r][c]);

			}
			System.out.print("\n");

		}
	}

}