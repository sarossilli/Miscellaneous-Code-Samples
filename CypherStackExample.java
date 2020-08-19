
// Sam Rossilli 
// CS 1450: 001
// Assignment 8: 4/9/19
// This program decrypts messages using a route cypher. It uses an array list for the first message
// and a queue for the second

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CypherStackExample {
	public static void main(String[] args) throws FileNotFoundException {
		// 1st secret message
		ArrayList<Character> messageList = new ArrayList<Character>();
		ArrayList<Character> keyList = new ArrayList<Character>();

		// Read the string in
		File file = new File("listMessage.txt");
		Scanner fileReader = new Scanner(file);
		String message = fileReader.next();

		System.out.println("Original Msg:" + message);
		for (int i = 0; i < message.length(); i++) {
			messageList.add(message.charAt(i));
		}

		// Read in info from key file
		file = new File("listKey.txt");
		fileReader = new Scanner(file);

		String key = fileReader.next();
		int[] size = { fileReader.nextInt(), fileReader.nextInt() };
		int[] start = { fileReader.nextInt(), fileReader.nextInt() };
		// Get Each Char of the key string
		for (int i = 0; i < key.length(); i++) {
			keyList.add(key.charAt(i));
		}
		// Create iterators
		Iterator<Character> msgIterator = messageList.iterator();
		Iterator<Character> keyIterator = keyList.iterator();

		// Create a decoded with the size/starting point
		Decoder decoder = new Decoder(size[0], size[1], start[0], start[1]);

		// Decode msg
		String decoded = decoder.unscramble(msgIterator, keyIterator);
		System.out.println("Decoded Msg: " + decoded);

		// Create queues for 2nd msg
		Queue<Character> queueMessage = new LinkedList<Character>();
		Queue<Character> queueKey = new LinkedList<Character>();

		// Read in queue key
		file = new File("queueKey.txt");
		fileReader = new Scanner(file);

		String queueKeyString = fileReader.next();
		int[] queueSize = { fileReader.nextInt(), fileReader.nextInt() };
		int[] queueStart = { fileReader.nextInt(), fileReader.nextInt() };

		// Get each char of the key string
		for (int i = 0; i < queueKeyString.length(); i++) {
			queueKey.add(queueKeyString.charAt(i));
		}

		// Read in from queueMessage
		file = new File("queueMessage.txt");
		fileReader = new Scanner(file);

		String queueMessageString = fileReader.next();
		System.out.println("Original msg: " + queueMessageString);

		// Get each char in the queue
		for (int i = 0; i < queueMessageString.length(); i++) {
			queueMessage.add(queueMessageString.charAt(i));
		}

		// Remake the itterator
		msgIterator = queueMessage.iterator();
		keyIterator = queueKey.iterator();

		// Remake decoded
		decoder = new Decoder(queueSize[0], queueSize[1], queueStart[0], queueStart[1]);

		// Decode msg
		String queueDecoded = decoder.unscramble(msgIterator, keyIterator);
		System.out.println("Decoded Msg: " + queueDecoded);

	}

}

class Decoder {
	char[][] messageArray;
	int startingRow;
	int startingCol;
	Stack stack;

	// Constructor that sets sizes for arrays and starting positions
	public Decoder(int numRows, int numCols, int startingRow, int startingCol) {
		this.startingRow = startingRow;
		this.startingCol = startingCol;
		this.messageArray = new char[numRows][numCols];
		stack = new Stack();
	}

	// Decodes a message using a route cypher.
	public String unscramble(Iterator<Character> msgIterator, Iterator<Character> keyIterator) {
		// Read Message into array
		for (int c = 0; c < messageArray[0].length; c++) {
			for (int r = 0; r < messageArray.length; r++) {
				messageArray[r][c] = msgIterator.next();
			}
		}

		// initialize row/column
		int row = startingRow;
		int col = startingCol;

		// Add each value to the stack:
		stack.push(messageArray[row][col]);
		while (keyIterator.hasNext()) {
			char key = keyIterator.next();
			// move row/col based on key
			if (key == 'r') {
				col++;
			} else if (key == 'l') {
				col--;
			} else if (key == 'u') {
				row--;
			} else if (key == 'd') {
				row++;
			}
			// add new char
			stack.push(messageArray[row][col]);
		}

		// Create string from stack
		String decoded = "";
		while (!stack.isEmpty()) {
			decoded += stack.pop();
		}
		return decoded;
	}
}

class Stack {
	ArrayList<Character> list = new ArrayList<Character>();

	// Returns true if stack is empty
	public boolean isEmpty() {
		list.trimToSize();
		return list.isEmpty();
	}

	// returns the size of the stack
	public int getSize() {
		list.trimToSize();
		return list.size();
	}

	// puts a value in the top of the stack
	public void push(char value) {
		list.add(0, value);
	}

	// Remove from top of stack
	public char pop() {
		return list.remove(0);
	}
}
