#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Record
{
    int cod;
	char nombre[12];
	int ciclo;
	
	long left, right;
};

class AVLFile
{
private:
    string filename;
    long pos_root;
public:
    AVLFile(string filename){
		this -> pos_root = 0;
		this->filename = filename;
	}
	
    Record find(int key){
		return find(pos_root, key);
	}
	
	
private:
	Record find(long pos_node, int key){

		ifstream file(filename, ios::binary);
        if (!file)
        {
            cerr << "Error" << endl;
        }

        file.seekg(pos_node);
        Record node;
        file.read(reinterpret_cast<char *>(&node), sizeof(Record));

        if (node.cod == key)
        {
            file.close();
            return node;
        }
        else if (key < node.cod && node.left != -1)
        {
            file.close();
            return find(node.left, key);
        }
        else if (key > node.cod && node.right != -1)
        {
            file.close();
            return find(node.right, key);
        }
        else
        {
            file.close();

        }
	}
};