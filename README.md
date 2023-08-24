# bd2_avl

P1: AVL File: Usando como base los algoritmos de búsqueda e inserción del AVL, se le pide adaptarlos
para trabaja con archivos de registros de longitud fija.
a) Implemente la función de búsqueda dado una search-key.
b) Implemente la función para agregar un nuevo registro.
a) Implemente una función para leer todos los registros ordenados.

struct Record
{
//Defina el registro y los campos adicionales
};
class AVLFile
{
private:
    string filename;
    long pos_root;
public:
    AVLFile(string filename);
    Record find(TK key);
