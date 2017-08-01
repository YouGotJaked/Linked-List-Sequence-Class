/* 
 * File:   main.cpp
 * Author: jakeday
 *
 * Created on May 17, 2017, 12:14 PM
 */

#include <iostream>
#include <cstdlib>
#include "sequence.h"

using namespace coen70_lab6;

/*
int test1(); // test list head insert, list head remove, list insert, list remove, list clear, and list length, 5 points
int test2(); // test list search, list occurrence and list located functions. 1 point
int test3();
int test4();

int main()
{

	int totalScore = 0;

	std::cout << "Let's see your grade. \n\n";
	system("pause");
	std::cout << std::endl;

	int score = test1();
	if (score == 0)
	{
		std::cout << "Basic insert function failed. No test will continue. Your score is 0.\n End testing program!\n";
		system("pause");
		return 0;
	}

	totalScore += score;
	std::cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	std::cout << std::endl;

	score = test2();
	if (score == 0)
		std::cout << "Test 2 failed\n";
	else
		std::cout << "Test 2 passed\n";
        totalScore += score;
	std::cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	std::cout << std::endl;
        
        score = test3();
	if (score == 0)
		std::cout << "Test 3 failed\n";
	else
		std::cout << "Test 3 passed\n";
	totalScore += score;
	std::cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	std::cout << std::endl;

	score = test4();
	if (score == 0)
		std::cout << "Test 4 failed\n";
	else
		std::cout << "Test 4 passed\n";
	totalScore += score;
	std::cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
        std::cout << std::endl;

	std::cout << "If you turn in your program to Dr. Zeng now, your will get " << totalScore << " out of 10\n";
	std::cout << "Dr. Zeng will read your program, check your program style\n and decide if you will get 1 less point\n";

	system("pause");
	return 0;
}

int test1()
{
	node* list = NULL; // an empty list
	list_head_insert(list, 0); // list contains one element 0;
	if (list == NULL || list->data() != 0 || list->link() != NULL)
	{
		std::cout << "list_head_insert function doesn't work for empty list\n";
		return 0;
	}

	list_head_insert(list, 1);
	list_head_insert(list, 2); // now list contains 2, 1, 0
	if (list->data() != 2 || list->link()->data() != 1 || list->link()->link()->data() != 0)
	{
		std::cout << "list_head_insert function doesn't work for non-empty list\n";
		return 0;
	}

	std::cout << "list_head_insert function passes the test\n";
        
	if (list_length(list) != 3)
	{
		std::cout << "list_length function is wrong\n";
		return 0;
	}

	list_head_remove(list); // now list contains 1, 0
	if (list->data() != 1 || list->link()->data() != 0)
	{
		std::cout << "list_head_remove function doesn't work\n";
		return 0;
	}

	list_head_remove(list);
	list_head_remove(list); // now list is empty

	if (list != NULL)
	{
		std::cout << "list_head_remove function doesn't work for one node list\n";
		return 0;
	}

	if (list_length(list) != 0)
	{
		std::cout << "list_length function is wrong for empty list";
		return 0;
	}

	std::cout << "list_head_remove passes the test\n";
	std::cout << "list_length passes the test\n";

	int i;
	for (i = 1; i <= 10; i++)
		list_head_insert(list, i);
	// now list contains 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
	list_clear(list);
	if (list != NULL)
	{
		std::cout << "list_clear function is not correct\n";
		return 0;
	}

	std::cout << "list_clear function passes the test\n";

	list_head_insert(list, 1); // now list contains 1
	for (i = 2; i <= 4; i++)
		list_insert(list, i);
	// now list contains 1, 4, 3, 2
	if (list_length(list) != 4 || list->data() != 1 || list->link()->data() != 4 || list->link()->link()->data() != 3)
	{
		std::cout << "list_insert function is wrong\n";
		return 0;
	}

	std::cout << "list_insert function passes the test\n";

	node* cursor = list->link(); // cursor points to 4
	list_remove(cursor); // now list contains 1, 4, 2
	if (list_length(list) != 3 || list->data() != 1 || list->link()->data() != 4 || list->link()->link()->data() != 2)
	{
		std::cout << "list_remove function is wrong\n";
		return 0;
	}

	std::cout << "list_remove function passes the test\n";

	return 5;
}

int test2()
{
	node* list = NULL; // an empty linked list
	int i;
	for (i = 1; i <= 5; i++)
	{
		if (i % 2 == 0)
			list_head_insert(list, i - 1);
		else
			list_head_insert(list, i);
	} // now list contains 5, 3, 3, 1, 1

	if (list_search(list, 2) != NULL)
	{
		std::cout << "list_search function doesn't work for not found case\n";
		return 0;
	}

	if (list_search(list, 3) != list->link())
	{
		std::cout << "list_search function doesn't work for found case\n";
		return 0;
	}

	std::cout << "list_search function passes the test\n";

	if (list_occurrences(list, 3) != 2 || list_occurrences(list, 5) != 1 || list_occurrences(list, 2) != 0)
	{
		std::cout << "list_occurrences function doesn't work\n";
		return 0;
	}

	std::cout << "list_occurrences function passes the test\n";

	if (list_locate(list, 2) != list_search(list, 3) || list_locate(list, 6) != NULL)
	{
		std::cout << "list_locate function doesn't work\n";
		return 0;
	}

	std::cout << "list_locate function passes the test\n";

	return 1;
}

int test3() // test list tail attach, and list tail remove functions 2 points
{
	node* list = NULL; // an empty list
	list_insert(list, 0); // list contains one element 0;
	if (list == NULL || list->data() != 0 || list->link() != NULL)
	{
		std::cout << "list_tail_attach function doesn't work for empty list\n";
		return 0;
	}

	list_insert(list, 1);
	list_insert(list, 2); // now list contains 0, 1, 2
	if (list->data() != 0 || list->link()->data() != 1 || list->link()->link()->data() != 2)
	{
		std::cout << "list_tail_attach function doesn't work for non-empty list\n";
		return 0;
	}

	std::cout << "list_tail_attach function passes the test\n";

	//list_insert(list); // now list contains 0, 1
	if (list->data() != 0 || list->link()->data() != 1 || list_length(list) != 2)
	{
		std::cout << "list_head_remove function doesn't work\n";
		return 0;
	}

	//list_insert(list);
	//list_insert(list); // now list is empty

	if (list != NULL)
	{
		std::cout << "list_tail_remove function doesn't work for one node list\n";
		return 0;
	}

	std::cout << "list_tail_remove function passes the test\n";

	return 2;

}

int test4()
{
	node* list = NULL; // an empty list
	node* copy = NULL;
	list_insert(list, 3);
	if (list != NULL)
	{
		std::cout << "list_copy_front function doesn't work for copying empty list\n";
		return 0;
	}
	for (int i = 1; i <= 4; i++)
		list_insert(list, i);
	// list contains 1, 2, 3, 4

	list_insert(list, 3);
	if (list_length(list) != 3 || copy->data() != 1 || copy->link()->data() != 2 || copy->link()->link()->data() != 3)
	{
		std::cout << "list_copy_front function doesn't work\n";
		return 0;
	}

	//list->link()->data() = 100;
	if (list->link()->data() == 100)
	{
		std::cout << "list_copy_front function doesn't work.\n";
		return 0;
	}
	list_clear(copy);
	copy = list_copy_segment(list, 6,6);
	if (list_length(copy) != 4)
	{
		std::cout << "list_copy_front function doesn't work\n";
		return 0;
	}

	std::cout << "list_copy_front passes the test\n";
        
	list_clear(list);
	for (int i = 1; i <= 3; i++)
		list_head_insert(list, i);
	// list contains 3, 2, 1

	//list_copy(list, copy);
	if (list_length(copy) != 3 || copy->data() != 3 || copy->link()->data() != 2 || copy->link()->link()->data() != 1)
	{
		std::cout << "list_copy function doesn't work\n";
		return 0;
	}

	std::cout << "list_copy function passes the test\n";

	return 2;

}
*/

int main() {
    sequence s;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    s.insert(10);
    std::cout << "current: " << s.current() << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    s.insert(-3);
    s.insert(13);
    s.insert(2);
    std::cout << "current: " << s.current() << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    s.start();
    s.insert(3);
    std::cout << "current: " << s.current() << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    s.attach(5);
    std::cout << "current: " << s.current() << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    s.remove_current();
    std::cout << "current: " << s.current() << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "is item: " << s.is_item() << std::endl;
    
    sequence s2 = s;
    s2.insert(6);
    s2.attach(65);
    std::cout << "current: " << s2.current() << std::endl;
    std::cout << "size: " << s2.size() << std::endl;
    std::cout << "is item: " << s2.is_item() << std::endl;
}

