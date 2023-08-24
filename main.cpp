#include "avl.cpp"

void writeFile(string filename){
    AVLFile file(filename);
    Record record;
    for (int i = 0; i < 4; i++)
    {
        record.setData();
        file.insert(record);
    }
}

void readFile(string filename){
    AVLFile file(filename);
    cout<<"--------- show all sorted data -----------\n";
    vector<Record> result = file.inorder();
    for(Record re : result){
        re.showData();
    }
}

int main(){
    writeFile("data.dat");
    readFile("data.dat");
    return 0;
}