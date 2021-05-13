#include<cstdlib>
#include<iostream>
#include"singlyLinkedList.cpp"

using namespace std;

int getData()
{
    cout << "Digite o elemento (int): ";
    int newData;
    cin >> newData;
    return newData;
}

int getPos()
{
    cout << "Digite a posição que deseja (int): ";
    int position;
    cin >> position;
    return position;
}

int main()
{
    LinkedList list;
    bool loop = true;
    int data, position;
    while(loop)
    {
        cout << "\nTestando o TAD Lista Simplesmente Ligada\n";
        cout << "[0] - Sair\n";
        cout << "[1] - Inserir no início\n";
        cout << "[2] - Inserir na posição n\n";
        cout << "[3] - Inserir no final\n";
        cout << "[4] - Inserir após a posição n\n";
        cout << "[5] - Inserir antes da posição n\n";
        cout << "[6] - Excluir um nó da posição n\n";
        cout << "[7] - Excluir um nó após a posição n\n";
        cout << "[8] - Excluir um nó antes da posição n\n";
        cout << "[9] - Excluir o primeiro nó que tenha valor n\n";
        cout << "[10] - Excluir toda a lista\n";
        cout << "[11] - Informar o tamanho da lista\n";
        cout << "[12] - Imprimir a lista\n";
        cout << "[13] - Procurar um valor na lista (Primeira aparição)\n";
        cout << "\nInforme sua opção:\n";
        
        int opc;
        cin >> opc;
        cout << endl;
        switch (opc)
        {
        case 0:
            loop = false;
            break;

        case 1:
            data = getData();
            list.push(data);
            cout << endl;
            list.printList(); 
            break;
        
        case 2:
            data = getData();
            position = getPos();
            list.pushOnPos(position, data);
            cout << endl;
            list.printList();
            break;

        case 3:
            data = getData();
            list.append(data);
            cout << endl;
            list.printList();
            break;
        
        case 4:
            data = getData();
            position = getPos();
            list.pushAfter(position, data);
            cout << endl;
            list.printList();
            break;
        
        case 5:
            data = getData();
            position = getPos();
            list.pushBefore(position, data);
            cout << endl;
            list.printList();
            break;
        
        case 6:
            position = getPos();
            list.delOnPos(position);
            cout << endl;
            list.printList();
            break;
        
        case 7:
            position = getPos();
            list.delAfter(position);
            cout << endl;
            list.printList();
            break;

        case 8:
            position = getPos();
            list.delBefore(position);
            cout << endl;
            list.printList();
            break;
        
        case 9:
            data = getData();
            list.Delete(data);
            cout << endl;
            list.printList();
            break;

        case 10:
            list.deleteAll();
            cout << endl;
            list.printList();
            break;

        case 11:
            int size;
            size = list.Size();
            cout << "\nA lista tem " << size << " elementos.\n";
            break;
        
        case 12:
            list.printList();
            break;

        case 13:
            data = getData();
            list.Search(data);
            break;

        default:
            cout << "\nOpção inválida! Digite uma opção presente no menu abaixo:\n";
            break;
        }
    }

    cout << "\nFim da operação.";
    return 0;
}