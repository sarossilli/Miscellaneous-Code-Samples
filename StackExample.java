// Sam Rossilli 
// CS 1450 Sec 001
// Assignment 5
// Due 2/28/19
// This program creates a generic stack, reads values from a file, and then 
// sorts the stack by value and removes duplicates.

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class StackExample {

	public static void main(String[] args) throws IOException {

		System.out.println(
				"Values read from numbers1.txt and pushed onto stack1 \n----------------------------------------------");
		// Open file for reading with a scanner
		File file = new File("numbers1.txt");
		Scanner fileReader = new Scanner(file);

		GenericStack<Integer> stackOne = new GenericStack<Integer>();
		while (fileReader.hasNextInt()) {
			// Add value to stack
			stackOne.push(fileReader.nextInt());
			// Print out the value
			System.out.println(stackOne.peek());
		}
		fileReader.close();
		// End of numbers1

		System.out.println(
				"\nValues read from numbers2.txt and pushed onto stack2 \n----------------------------------------------");
		// Change file to numbers2
		file = new File("numbers2.txt");
		fileReader = new Scanner(file);

		GenericStack<Integer> stackTwo = new GenericStack<Integer>();
		while (fileReader.hasNextInt()) {
			stackTwo.push(fileReader.nextInt());
			System.out.println(stackTwo.peek());
		}
		fileReader.close();
		// End of numbers2

		// Combine them
		GenericStack<Integer> combinedStack = new GenericStack<Integer>();
		combineStacks(stackOne, stackTwo, combinedStack);

		// Sort the combined stack
		GenericStack<Integer> sortedStack = new GenericStack<Integer>();
		sortStack(combinedStack, sortedStack);

		// Remove doubles in sorted Stack
		removeDuplicates(sortedStack);

		// Display stack
		System.out.println("\n\nCombined Number Stack with lowest value on top: ");
		printStack(sortedStack);

		// Read Strings into Stack
		System.out.println(
				"\nValues read from strings1.txt and pushed onto stack1\n--------------------------------------------------");
		// Change file to Strings one
		file = new File("strings1.txt");
		fileReader = new Scanner(file);

		GenericStack<String> stringOne = new GenericStack<String>();
		while (fileReader.hasNext()) {
			stringOne.push(fileReader.next());
			System.out.println(stringOne.peek());
		}
		fileReader.close();
		// End of String One

		// Read Strings into Stack
		System.out.println(
				"\nValues read from strings1.txt and pushed onto stack1\n--------------------------------------------------");
		// Change file to Strings 2
		file = new File("strings2.txt");
		fileReader = new Scanner(file);

		GenericStack<String> stringTwo = new GenericStack<String>();
		while (fileReader.hasNext()) {
			stringTwo.push(fileReader.next());
			System.out.println(stringTwo.peek());
		}
		fileReader.close();
		// End of numbers 2

		// Combine the stacks
		GenericStack<String> combinedStrings = new GenericStack<String>();
		combineStacks(stringOne, stringTwo, combinedStrings);

		// Sort the stack
		GenericStack<String> sortedStrings = new GenericStack<String>();
		sortStack(combinedStrings, sortedStrings);

		// Remove any duplicates
		removeDuplicates(sortedStrings);

		// Display Stack
		System.out.println(
				"\n\nCombined String Stack with lowest value on top: \n----------------------------------------------------------");
		printStack(sortedStrings);
	}

	public static <E> void combineStacks(GenericStack<E> stack1, GenericStack<E> stack2,
			GenericStack<E> combinedStack) {
		// Method that combines two stacks into one stack

		while (!stack1.isEmpty()) {
			// Pop the first stacks values to the final stack until it is empty
			combinedStack.push(stack1.pop());
		}
		while (!stack2.isEmpty()) {
			// Pop the second stacks values to the final stack until it is empty
			combinedStack.push(stack2.pop());
		}
	}

	public static <E extends Comparable<E>> void sortStack(GenericStack<E> unsortedStack, GenericStack<E> sortedStack) {
		// Method that sorts stack by value

		while (!unsortedStack.isEmpty()) {
			// Pop one value off
			E value = unsortedStack.pop();

			// If the top of sorted is less than the value (is out of order), pop the sorted
			// value back
			while (!sortedStack.isEmpty() && ((sortedStack).peek().compareTo(value) < 0)) {
				unsortedStack.push(sortedStack.pop());
			}
			// After the correct place is found, push the value to sorted stack.
			sortedStack.push(value);
		}
	}

	public static <E extends Comparable<E>> void removeDuplicates(GenericStack<E> stack) {
		// Method to remove duplicate values on a stack
		GenericStack<E> temp = new GenericStack<E>();

		// CHeck if there is at least one value to pop
		while (stack.size() > 1) {
			// pop it to temp stack
			temp.push(stack.pop());
			// if it is a duplicate value, remove it from temp
			if (temp.peek().compareTo(stack.peek()) == 0) {
				temp.pop();
			}
		}
		// Add values back to original stack
		for (int i = temp.size(); i > 0; i--) {
			stack.push(temp.pop());
		}

	}

	public static <E> void printStack(GenericStack<E> stack) {
		// Create temp to prevent loosing poped stack values
		GenericStack<E> temp = new GenericStack<E>();
		for (int i = stack.size(); i > 0; i--) {
			System.out.println(stack.peek());
			temp.push(stack.pop());
		}
		// Add values back to original stack
		for (int i = temp.size(); i > 0; i--) {
			stack.push(temp.pop());
		}
	}
}

class GenericStack<E> {
	private ArrayList<E> stack;

	public GenericStack() {
		this.stack = new ArrayList<E>();

	}

	public void push(E value) {
		stack.add(value);
	}

	public E peek() {
		E top = stack.get((stack.size() - 1));
		return top;
	}

	public E pop() {
		E top = this.peek();
		stack.remove(stack.size() - 1);
		return top;
	}

	public int size() {
		return stack.size();
	}

	public boolean isEmpty() {
		stack.trimToSize();
		if (stack.size() == 0) {
			return true;
		}
		return false;
	}

}
