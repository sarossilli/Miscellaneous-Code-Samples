// Sam Rossilli 
// CS 1450: 001
// Assignment 10: 4/18/19
// This program creates a linked list of "waypoints" to give a list of tasks in a journey
// It reads waypoints from a file and adds them to a linked list by distance
// It then reverses the list and finds the return journey list

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class LinkedListExample {

	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("parrots.txt");
		Scanner reader = new Scanner(file);

		BinaryTree tree = new BinaryTree();

		// Read in values and add parrots to tree
		while (reader.hasNext()) {
			tree.insert(new Parrot(reader.nextInt(), reader.next()));
		}
		reader.close();

		// Print each birds word by level order traversal of the tree
		tree.levelOrder();

	}
}

//Class Represents a Parrot
class Parrot implements Comparable<Parrot> {
	private int id;
	private String word;

	public Parrot(int id, String word) {
		this.id = id;
		this.word = word;
	}

	// Returns a string of the bird's single word
	public String sing() {
		return word;
	}

	// Implemntaion of compareable
	@Override
	public int compareTo(Parrot otherParrot) {
		if (this.id < otherParrot.id) {
			return -1;
		} else if (this.id > otherParrot.id) {
			return 1;
		}
		return 0;
	}

}

// Represents a binary tree
class BinaryTree {
	private TreeNode root;

	// Constructor initializes root as null
	public BinaryTree() {
		this.root = null;
	}

	// Method that inserts the parrot in tree according to compareTo method
	public boolean insert(Parrot parrot) {
		// Check for empty tree
		if (root == null) {
			root = new TreeNode(parrot);
		}
		// If the tree is not empty:
		else {
			// Set pointer to current and next node
			TreeNode current = root;
			TreeNode previous = null;

			// Repeat untill reaching the end of the tree
			while (current != null) {
				// Move previous up one node
				previous = current;
				// Check if parrot is less or greater than current level node
				if ((current.parrot.compareTo(parrot)) > 0) {
					// Move left is parrot is smaller
					current = current.left;
				} else if ((previous.parrot.compareTo(parrot)) < 0) {
					// move right if parrot is bigger
					current = current.right;
				} else {
					// Dont add parrot if duplicate
					return false;
				}
			}
			// Add parrot in correct spot:
			// Right if parrot is smaller than previous node
			// Left if parrot is larger
			if ((previous.parrot.compareTo(parrot)) < 0) {
				previous.right = new TreeNode(parrot);
			} else {
				previous.left = new TreeNode(parrot);
			}
		}
		// Returns true if parrot successfully added
		return true;
	}

	// Method traverses the tree according to level order and prints each birds word
	public void levelOrder() {
		// Check if tree is empty
		if (root != null) {
			// Create queue and add root
			Queue<TreeNode> queue = new LinkedList<TreeNode>();
			queue.add(root);
			while (!queue.isEmpty()) {
				// Pull one value of queue and print
				TreeNode temp = queue.remove();
				System.out.println(temp.parrot.sing());

				// Check and add temp's child nodes
				if (temp.left != null) {
					queue.add(temp.left);
				}
				if (temp.right != null) {
					queue.add(temp.right);
				}
			}
		}
	}

	// Methd represents a tree node
	private class TreeNode {
		private Parrot parrot;
		private TreeNode right;
		private TreeNode left;

		// Constuctor creates a node with parrot and sets left/right as null
		public TreeNode(Parrot parrot) {
			this.parrot = parrot;
			this.right = null;
			this.left = null;
		}
	}
}