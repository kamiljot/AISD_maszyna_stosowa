#include <iostream>
using namespace std;

struct node{
    int numb;
    node * next;
};

void printStack (node * _node){
    cout << _node->numb << " ";
    if (_node->next->next != nullptr){
        printStack(_node->next);
    }
}

node * push(char * input, node * head){
    node * _new = new node;
    _new->next = head;
    if (*(input + 1) != NULL){
        _new->numb = ((int)*input - 48)*10 + ((int)*(input + 1) - 48);
    } else {
        _new->numb = (int)*input - 48;
    }
    head = _new;
    return head;
}

node * switch_(node * head){
    node * _head = new node;
    _head = head->next;
    head->next = _head->next;
    _head->next = head;
    return _head;
}

node * pop(node * head){
    return head->next;
}

node * add(node * head){
    if (head->next != nullptr){
        head->next->numb += head->numb;
        return pop(head);
    }
}

node * insert(node * head){
    int value = head->numb;
    node * _new = new node;
    head = pop(head);
    _new = head;
    if (value <= 1){
        return head;
    } else{
        if (value == 2){
            return switch_(head);
        } else{
            for (int i = 1; i < value; i++){
                _new = _new->next;
            }
            return head->next;
        }
    }
}

int main()
{
    node * head = new node;
    head->next = nullptr;
    char * input = new char[2];

    while(scanf("%s", input)){
        switch (*input){
            case 'p':
                printStack(head);
                cout << endl;
                break;
            case 's':
                head = switch_(head);
                break;
            case 'x':
                head = pop(head);
                break;
            case 43:
                head = add(head);
                break;
            case 'r':
                head = insert(head);
                break;
            case 'q':
                return 666;
                break;
            default:
                head = push(input, head);
                break;
        }
    }
}