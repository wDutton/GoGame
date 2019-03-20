// DepthFirstSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <tuple>
#include <string.h>


using namespace std;

class node {//for a grid

private:
	string data;
	int nodeNum;
	node* north;
	node* south;
	node* east;
	node* west;

	//4 directions to possibly point
public:
	node()
	{
		nodeNum = 0;
		data = "";
		north = south = east = west = NULL;
	}

	node(int n, string d)
	{
		data = d;
		nodeNum = n;
		north = south = east = west = NULL;
	}

	//bunch of getters/setters

	void setNodeNum(int n)
	{
		nodeNum = n;
	}

	int getNodeNum()
	{
		return nodeNum;
	}

	void setData(string d) {
		data = d;
	}

	string getData() {
		return data;
	}

	void setNorth(node* n)
	{
		north = n;
	}

	node *getNorth()
	{
		return north;
	}

	void setSouth(node* s) {
		south = s;
	}

	node *getSouth() {
		return south;
	}

	void setEast(node *e) {
		east = e;
	}

	node *getEast() {
		return east;
	}

	void setWest(node *w) {
		west = w;
	}

	node *getWest() {
		return west;
	}

};
void printNodes(node* array[][9]) {
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			//top left node

			if (array[row][col]->getNodeNum() == 0) {
				cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast()->getNodeNum() << "     West: " << array[row][col]->getWest() << endl; //prints which node that current node has connections to. 0 = Null.... rest should match with drawing (works)
			}

			//bottom left node
			else if (array[row][col]->getNodeNum() == 72) {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest() << endl;
			}

			//top right node
			else if (array[row][col]->getNodeNum() == 8) {
				cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//bottom right node
			else if (array[row][col]->getNodeNum() == 80) {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//top row
			else if (array[row][col]->getNodeNum() > 0 && array[row][col]->getNodeNum() < 8) {
				cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast()->getNodeNum() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}


			//bottom row
			else if (array[row][col]->getNodeNum() > 72 && array[row][col]->getNodeNum() < 80) {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//left side
			else if (array[row][col]->getNodeNum() == 9 || array[row][col]->getNodeNum() == 18 || array[row][col]->getNodeNum() == 27 || array[row][col]->getNodeNum() == 36 || array[row][col]->getNodeNum() == 45 || array[row][col]->getNodeNum() == 54 || array[row][col]->getNodeNum() == 63) {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest() << endl;
			}

			// right side
			else if (array[row][col]->getNodeNum() == 17 || array[row][col]->getNodeNum() == 26 || array[row][col]->getNodeNum() == 35 || array[row][col]->getNodeNum() == 44 || array[row][col]->getNodeNum() == 53 || array[row][col]->getNodeNum() == 62 || array[row][col]->getNodeNum() == 71) {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;

			}

			//everything left in middle
			else {
				cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

		}

	}
}
void linkNodes(node* array[][9])
{
	int count = 0; //every node has their own count because there are 81 adjacency lists
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			//top left node

			if (array[row][col]->getNodeNum() == 0) {
				array[row][col]->setSouth(array[row + 1][col]);
				array[row][col]->setEast(array[row][col + 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast()->getNodeNum() << "     West: " << array[row][col]->getWest() << endl; //prints which node that current node has connections to. 0 = Null.... rest should match with drawing (works)
			}

			//bottom left node
			else if (array[row][col]->getNodeNum() == 72) {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setEast(array[row][col + 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest() << endl;
			}

			//top right node
			else if (array[row][col]->getNodeNum() == 8) {
				array[row][col]->setWest(array[row][col - 1]);
				array[row][col]->setSouth(array[row + 1][col]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//bottom right node
			else if (array[row][col]->getNodeNum() == 80) {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setWest(array[row][col - 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//top row
			else if (array[row][col]->getNodeNum() > 0 && array[row][col]->getNodeNum() < 8) {
				array[row][col]->setSouth(array[row + 1][col]);
				array[row][col]->setEast(array[row][col + 1]);
				array[row][col]->setWest(array[row][col - 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "     North: " << array[row][col]->getNorth() << "     South: " << array[row][col]->getSouth()->getNodeNum() << "     East: " << array[row][col]->getEast()->getNodeNum() << "     West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}


			//bottom row
			else if (array[row][col]->getNodeNum() > 72 && array[row][col]->getNodeNum() < 80) {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setEast(array[row][col - 1]);
				array[row][col]->setWest(array[row][col + 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

			//left side
			else if (array[row][col]->getNodeNum() == 9 || array[row][col]->getNodeNum() == 18 || array[row][col]->getNodeNum() == 27 || array[row][col]->getNodeNum() == 36 || array[row][col]->getNodeNum() == 45 || array[row][col]->getNodeNum() == 54 || array[row][col]->getNodeNum() == 63) {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setSouth(array[row + 1][col]);
				array[row][col]->setEast(array[row][col + 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest() << endl;
			}

			// right side
			else if (array[row][col]->getNodeNum() == 17 || array[row][col]->getNodeNum() == 26 || array[row][col]->getNodeNum() == 35 || array[row][col]->getNodeNum() == 44 || array[row][col]->getNodeNum() == 53 || array[row][col]->getNodeNum() == 62 || array[row][col]->getNodeNum() == 71) {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setSouth(array[row + 1][col]);
				array[row][col]->setWest(array[row][col - 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;

			}

			//everything left in middle
			else {
				array[row][col]->setNorth(array[row - 1][col]);
				array[row][col]->setSouth(array[row + 1][col]);
				array[row][col]->setEast(array[row][col + 1]);
				array[row][col]->setWest(array[row][col - 1]);
				//cout << "Node: " << array[row][col]->getNodeNum() << "    North: " << array[row][col]->getNorth()->getNodeNum() << "    South: " << array[row][col]->getSouth()->getNodeNum() << "      East: " << array[row][col]->getEast()->getNodeNum() << "    West: " << array[row][col]->getWest()->getNodeNum() << endl;
			}

		}
	}
}
void createNodes(node* nodeArray[9][9], string board[][9]) {
	int count = 0;
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {


			node* n = new node();
			nodeArray[row][col] = n;
			n->setNodeNum(count);
			n->setData(board[row][col]);
			count++;
		}
	}


}
void createAdjacencyList(node* nodeArray[][9], node* adjList[81]) {
	int counter = 0;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			adjList[counter] = nodeArray[row][col];
			counter++;
		}
	}
}
void printAdjList(node* adjList[81])
{
	for (int i = 0; i < 81; i++)
	{
		cout << adjList[i]->getData();
		if (adjList[i]->getEast() != NULL)
			cout << " -> " << adjList[i]->getEast()->getData();
		if (adjList[i]->getWest() != NULL)
			cout << " -> " << adjList[i]->getWest()->getData();
		if (adjList[i]->getNorth() != NULL)
			cout << " -> " << adjList[i]->getNorth()->getData();
		if (adjList[i]->getSouth() != NULL)
			cout << " -> " << adjList[i]->getSouth()->getData();

		cout << endl;


	}
}
struct info
{
	int score = 0;
	string color = "";
};



int score = 0;
bool colorGood;

info scoring(node* adjList[81], bool visited[81], int currentNode, string currentScoringColor)
{
	info in;
	int localScore = 1;
	visited[currentNode] = true;
	//cout << currentNode << " ";

	if (adjList[currentNode]->getEast() != NULL && visited[adjList[currentNode]->getEast()->getNodeNum()] == false) {
		if (adjList[currentNode]->getEast()->getData() == "E") {
			
			in = scoring(adjList, visited, adjList[currentNode]->getEast()->getNodeNum(), currentScoringColor);
			score = score + localScore;
		}
		else if(adjList[currentNode]->getEast()->getData() != currentScoringColor && adjList[currentNode]->getEast()->getData() != "E")
		{
			colorGood = false;
			cout << "they dont equal color = " << adjList[currentNode]->getEast()->getData() << "and curr scoring color = " << currentScoringColor << endl;
		}
	}
	if (adjList[currentNode]->getWest() != NULL && visited[adjList[currentNode]->getWest()->getNodeNum()] == false)
	{
		if (adjList[currentNode]->getWest()->getData() == "E") 
		{
			in = scoring(adjList, visited, adjList[currentNode]->getWest()->getNodeNum(), currentScoringColor);
			score = score + localScore;
		}
		else if (adjList[currentNode]->getWest()->getData() != currentScoringColor && adjList[currentNode]->getWest()->getData() != "E")
		{
			colorGood = false;
			cout << "they dont equal color = " << adjList[currentNode]->getWest()->getData()<< "and curr scoring color = " <<currentScoringColor<<endl;
		}
	}

	if (adjList[currentNode]->getNorth() != NULL && visited[adjList[currentNode]->getNorth()->getNodeNum()] == false) {
		if (adjList[currentNode]->getNorth()->getData() == "E") 
		{
			in = scoring(adjList, visited, adjList[currentNode]->getNorth()->getNodeNum(), currentScoringColor);
			score = score + localScore;
		}
		else if (adjList[currentNode]->getNorth()->getData() != currentScoringColor && adjList[currentNode]->getNorth()->getData() != "E"){
			colorGood = false;
			cout << "they dont equal color = " << adjList[currentNode]->getNorth()->getData() << "and curr scoring color = " << currentScoringColor << endl;
		}
	}
	if (adjList[currentNode]->getSouth() != NULL && visited[adjList[currentNode]->getSouth()->getNodeNum()] == false)
	{
		if (adjList[currentNode]->getSouth()->getData() == "E") 
		{
			in = scoring(adjList, visited, adjList[currentNode]->getSouth()->getNodeNum(), currentScoringColor);
			score = score + localScore;
		}
		else if (adjList[currentNode]->getSouth()->getData() != currentScoringColor && adjList[currentNode]->getSouth()->getData() != "E")
		{
			colorGood = false;
			cout << "they dont equal color = " << adjList[currentNode]->getSouth()->getData() << "and curr scoring color = " << currentScoringColor << endl;
		}
	}
	in.score = score;
	return in;
}


int main()
{
	string B = "B";
	string E = "E";
	string W = "W";
	node* adjList[81];

	string board[9][9] = {
	{B,E,B,E,E,E,E,E,E},
	{E,B,E,E,B,E,E,E,E},
	{B,E,B,B,B,B,E,E,E},
	{B,B,B,W,W,B,B,B,E},
	{B,B,W,E,E,W,W,B,E},
	{W,W,W,E,E,W,B,B,B},
	{E,E,E,W,E,W,W,B,B},
	{E,W,B,B,B,E,W,W,B},
	{E,E,B,E,B,W,W,W,W} };


	node* nodeArray[9][9];

	bool visited[81];
	for (int i = 0; i < 81; i++)
		visited[i] = false;

	createNodes(nodeArray, board);
	linkNodes(nodeArray);
	//printNodes(nodeArray);
	createAdjacencyList(nodeArray, adjList);
	//printAdjList(adjList);

	int whiteScore = 0;
	int blackScore = 0;
	for (int i = 0; i < 81; i++)
	{
		score = 0;
		info in;
		if (visited[i] == false && adjList[i]->getData() == "E") {
			//cout << "\n node start at: " << i << "  ";
			colorGood = true;
			string currentScoringColor;
			if(adjList[i]->getNorth() != NULL)
				if(adjList[i]->getNorth()->getData() != "E")
					currentScoringColor = adjList[i]->getNorth()->getData();

			if(adjList[i]->getSouth() != NULL)
				if (adjList[i]->getSouth()->getData() != "E")
					currentScoringColor = adjList[i]->getSouth()->getData();

			if (adjList[i]->getEast() != NULL)
				if (adjList[i]->getEast()->getData() != "E")
					currentScoringColor = adjList[i]->getEast()->getData();

			if (adjList[i]->getWest() != NULL)
				if (adjList[i]->getWest()->getData() != "E")
					currentScoringColor = adjList[i]->getWest()->getData();

			//cout << "cur color:   "<<currentScoringColor << endl;
			if (currentScoringColor == "B") {
				in = scoring(adjList, visited, i, currentScoringColor);
				if (colorGood == true)
				{
					blackScore = blackScore + in.score + 1;
					//cout << "added " <<in.score<< " to black score" << endl;
				}
			}
			if (currentScoringColor == "W") {
				in = scoring(adjList, visited, i, currentScoringColor);
				if (colorGood == true)
				{
					whiteScore = whiteScore + in.score + 1;
					//cout << "added "<< in.score<< " to white score" << endl;
				}
			}
		}
	}
	cout << "White score: " << whiteScore << endl;
	cout << "Black score: " << blackScore << endl;



	return 117;
}

