#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() { 
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->size_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
        return this->size_ / static_cast<double>(this->capacity());
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if (index > this->size_) {
            return false;
        }

        int_node* new_node = new int_node;
        new_node->value = value;

        if (index == 0) {
            new_node->next = this->head;
            new_node->prev = nullptr;
            if (this->head != nullptr) {
                this->head->prev = new_node;
            }
            this->head = new_node;
            if (this->tail == nullptr) {
                this->tail = new_node;
            }
        } else if (index == this->size_) {
            new_node->next = nullptr;
            new_node->prev = this->tail;
            if (this->tail != nullptr) {
                this->tail->next = new_node;
            }
            this->tail = new_node;
        } else {
            int_node* current = this->head;
            for (unsigned int i = 0; i < index; ++i) {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = new_node;
            }
            current->prev = new_node;
        }
        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido
        if (index >= this->size_) {
            return -1;
        }

        int_node* current = this->head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;

        if (this->tail != nullptr) {
            this->tail->next = new_node;
        }
        this->tail = new_node;

        if (this->head == nullptr) {
            this->head = new_node;
        }

        this->size_++;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;

        if (this->head == nullptr) {
            this->tail = new_node;
        }
        else {
            this->head->prev = new_node;
        }
        this->head = new_node;
        this->size_++;
    }
    bool pop_back() { // Remove um elemento do ``final'' do vetor
        if (this->tail == nullptr) {
            return false;
        }
        int_node* to_remove = this->tail;
        this->tail = this->tail->prev;
        if (this->tail != nullptr)
            this->tail->next = nullptr;
        else {
            this->head = nullptr;
        }
        delete to_remove;
        this->size_--;
        return true;
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if (this->head == nullptr) {
            return false;
        }
        int_node* to_remove = this->head;
        this->head = this->head->next;
        if (this->head != nullptr) {
            this->head->prev = nullptr;
        } else {
            this->tail = nullptr;
        }

        delete to_remove;
        this->size_--;
        return true;
    }
    int front() { // Retorna o elemento do ``início'' do vetor
        if(this->head == nullptr) {
            return -1;
        }
        return this->head->value;
    }
    int back() { // Retorna o elemento do ``final'' do vetor
        if (this->tail == nullptr) {
            return -1;
        }
        return this->tail->value;
    }
    bool remove(int value) { // Remove value do vetor caso esteja presente
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    this->head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    this->tail = current->prev;
                }
                delete current;
                this->size_--;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int_node* current = this->head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int_node* current = this->head;
        int count = 0;
        while (current != nullptr) {
            if (current->value == value) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        int_node* current = this->head;
        int sum = 0;
        while (current != nullptr) {
            sum += current->value;
            current = current->next;
        }
        return sum;
    }
};

#endif // __LINKED_LIST_IFRN__