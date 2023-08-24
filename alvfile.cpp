#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Record
{
    int cod;
    char nombre[12];
    int ciclo;

    long left, right;

    void setData() {
        cout << "Codigo:";
        cin >> cod;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Ciclo: ";
        cin >> ciclo;
    }

    void showData() {
        cout << "\nCodigo: " << cod;
        cout << "\nNombre: " << nombre;
        cout << "\nCiclo : " << ciclo <<endl;
    }
};

class AVLFile
{
private:
    string filename;
    long pos_root;
public:
    AVLFile(string filename){
        this->pos_root = 0;
        this->filename = filename;
        fstream file(filename, ios::binary | ios::in | ios::out);
        if(!file.is_open()){
            this->pos_root = -1;
        }
    }

    Record find(int key){
        return find(pos_root, key);
    }

    void insert(Record record){
        insert(pos_root, record);
    }

    vector<Record> inorder(){
        return inorder(pos_root);
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
        else {
            file.close();

        }
    }

    void insert(long pos_node, Record record){
        if (pos_node == -1){
            fstream file(filename, ios::binary | ios::in | ios::out);
            pos_node = file.tellp() / sizeof(Record);
            file.seekp(pos_node * sizeof(Record));
            file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
            file.close();
        }else{
            fstream file(filename, ios::binary | ios::in | ios::out);
            file.seekg(pos_node * sizeof(Record));
            Record node;
            file.read(reinterpret_cast<char*>(&node), sizeof(Record));
            file.close();
            if (record.cod < node.cod){
                insert(node.left, record);
            }
            else{
                insert(node.right, record);
            }
        }
    }
    vector<Record> inorder(long pos_node){

        ifstream file(filename, ios::binary);
        if (!file.is_open()) throw ("No se pudo abrir el archivo");

        vector<Record> result;
        if (pos_node == 0) {
            file.close();
            return result;
        }

        file.seekg(pos_node, ios::beg);
        Record node;
        file.read((char*)&node, sizeof(Record));
        file.close();

        if (node.cod == -1) {
            return result;
        }

        vector<Record> leftSubtree = inorder(node.left);
        result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());

        result.push_back(node);

        vector<Record> rightSubtree = inorder(node.right);
        result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());

        return result;

        }
};
