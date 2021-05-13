#include <cstdlib>
#include <iostream>
using namespace std;
  
class Node {
    public:
        int data;
        Node* next;

        Node(int newData)
        {
            data = newData;
            next = NULL;
        }
};

class LinkedList {
    public:
        Node *head, *tail;
        int size = 0;
        // Construtor da classe
        LinkedList()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        // Verifica se está vazia
        bool isEmpty()
        {
            return head == NULL;
        }

        // Retorna o tamanho da lista
        int Size()
        {
            return size;
        }

        // Insere no começo da lista
        void push(int newData)
        {
            Node* newNode = new Node(newData);
            // Verifica se está vazia, então faz o novo nó como head e tail
            if (isEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            // Se não, só adiciona outro nó no começo
            else
            {
                newNode->next = head;
                head = newNode;
            }
            size++;
            return;
        }

        // Insere na posição escolhida
        void pushOnPos(int position, int newData)
        {
            Node* newNode = new Node(newData);
            while (true) 
            {
                // int x = 2;

                if (position < 1)
                {
                    cout << "A posição deve ser maior ou igual a 1!\n";
                    return;
                }

                if (position > size + 1)
                {
                    cout << "Não existe essa posição! A fila está com " << size << " elementos.\n";
                    return;
                }

                if (isEmpty())
                {
                    head = newNode;
                    tail = newNode;
                    size++;
                    return;
                }

                if (position == 1)
                {
                    push(newData);
                    cout << "Inserido no início!\n";
                    return;
                }

                // Se for o último, muda o tail
                if (position == size+1)
                {
                    tail->next = newNode;
                    tail = tail->next;
                    size++;
                    return;
                }

                else
                {
                    Node* tmp = head;
                    for (int i = 1; i < position - 1; i++)
                    {
                        tmp = tmp->next;
                    }
                    newNode->next = tmp->next;
                    tmp->next = newNode;
                    size++;
                    return;
                }
            }
            return;
        }

        // Insere antes da posição escolhida
        void pushBefore(int position, int newData)
        {
            pushOnPos(position-1, newData);
        }

        // Insere depois da posição escolhida
        void pushAfter(int position, int newData)
        {
            pushOnPos(position+1, newData);
        }

        // Insere no final
        void append(int newData)
        {
            Node* newNode = new Node(newData);
            // Verifica se está vazia, então faz o novo nó como head e tail
            if (isEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            // Se não, adiciona o nó depois do tail e muda tail para o próprio node
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
            size++;
            return;
        }

        // Deleta o node que possui o dado da variável "targetData"
        void Delete(int targetData)
        {   
            // Armazena o nó head
            Node* tmp = head;
            Node* prev = NULL;
            // Se não estiver vazio e encontrar o dado desejado na primeira posição
            if (tmp != NULL && tmp->data == targetData)
            {
                head = tmp->next;  // Muda o head
                delete tmp;        // Libera o espaço de "tmp"
            }
            else
            {
                // Percorre os nós da lista enquanto não encontrar o dado desejado
                while (tmp != NULL && tmp->data != targetData)
                {
                    prev = tmp;
                    tmp = tmp->next;
                }
                if (tmp == NULL)
                {
                    cout << "O elemento " << targetData << " não está presente na lista.\n";
                    return;
                }
                // Se for o último, muda o tail
                if (tmp->next == NULL)
                {
                    tail = prev;
                }
                // Desconecta o nó da lista e deleta tmp
                prev->next = tmp->next;
                delete tmp;
            }
            cout << "O elemento [" << targetData << "] foi deletado da lista!\n";
            size--;
            return;
        }

        // Deleta o node na posição escolhida
        void delOnPos(int position)
        {
            if (isEmpty())
            {
                cout << "A lista está vazia!\n";
                return;
            }
            if (position < 1)
                {
                    cout << "A posição deve ser maior ou igual a 1!\n";
                    return;
                }

            // Armazena o nó head
            Node* tmp = head;
        
            // Se for remover o nó head
            if (position == 1)
            {
                head = tmp->next;
                free(tmp); 
                size--;        
                return;
            }

            // Percorre a lista até encontrar o node anterior ao que será deletado
            for(int i = 1; tmp != NULL && i < position - 1; i++)
                tmp = tmp->next;
            
            // Se for o último, muda o tail
            if (tmp->next->next == NULL)
                tail = tmp;

            // Se a posição dada for maior que o número de nós existentes
            if (tmp == NULL || tmp->next == NULL)
            {
                cout << "A posição " << position << " não se encontra na lista!\n";
                return;
            }
            
            // Armazena o ponteiro para o next do node que será deletado (Node tmp->next)
            Node *next = tmp->next->next;
            free(tmp->next);
            tmp->next = next;
            size--;
            return;
        }

        // Deleta na posição anterior
        void delBefore(int position)
        {
            delOnPos(position-1);
        }

        // Deleta na posição seguinte
        void delAfter(int position)
        {
            delOnPos(position+1);
        }

        // Deleta toda a lista
        void deleteAll()
        {
            while (head != NULL)
            {
                if (head->next != NULL)
                {
                    Node* tmp = head->next;
                    head->next = NULL;
                    free(head);
                    head = tmp;
                    size--;
                }
                else{
                    head = NULL;
                    size--;
                }
            }
        }

        // Deleta elementos repetidos
        void delRepeated()
        {
            Node* tmp1 = head;
            Node *tmp2, *del = NULL;
            while (tmp1 != NULL && tmp1->next != NULL)
            {
                // Muda o head de tmp2 para fazer comparações a partir do head "atual" do primeiro loop
                tmp2 = tmp1;
                while (tmp2->next != NULL)
                {
                    // cout << "Comparando [" << tmp1->data <<"] com [" << tmp2->next->data << "]\n";
                    if (tmp1->data == tmp2->next->data)
                    {
                        cout << "Elemento repetido deletado: "<< tmp1->data << endl;
                        del = tmp2->next;
                        tmp2->next = tmp2->next->next;
                        delete(del);
                    }
                    else
                        // Avança para o próximo node no segundo loop
                        tmp2 = tmp2->next;
                }
                // Avança para o próximo node no primeiro loop
                tmp1 = tmp1->next;
            }
            return;
        }

        // Procura um valor
        void Search(int targetData)
        {
            Node* tmp = head;
            int cont = 1;
            while (tmp != NULL)
            {   
                if (tmp->data == targetData)
                {
                    cout << "O dado [" << targetData <<"] foi encontrado na posição: " << cont << endl;
                    if (tmp->next != NULL)
                        cout << "Next [" << tmp->next->data << "]\n";
                    return;
                }
                tmp = tmp->next;
                cont++;
            }
            cout << "O dado [" << targetData << "] não foi encontrado na lista!\n";
            return;
        }

        // Imprime a lista
        void printList()
        {
            Node* tmp = head;
            cout << "[ ";
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << "]\n";
            return;
        }

        
};