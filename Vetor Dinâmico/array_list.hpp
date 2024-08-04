#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_;
    void increase_capacity() { //aumenta a capacidade do vetor
        int add_capacity = this->capacity_;
        int* new_data = new int[this->capacity_+add_capacity];
        for (unsigned int i=0 ; i<this->size_ ; ++i) {
            new_data[i] = data[i];
        }
        delete [] this->data;
        this->data = new_data;
        this->capacity_ = this->capacity_+add_capacity;
    }
public:
    array_list() { // Construtor
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
    }
    ~array_list() { // Destrutor
        delete[] data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada
        return static_cast<double>(this->size_) / this->capacity_;
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if (index > this->size_) {
            return false; // Não inseriu
        }
        if (this->size_ == this->capacity_) {
            this->increase_capacity();
        }
        for (unsigned int i = this->size_; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        this->size_++;
        return true; // Inseriu
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size_) {
            return false; // Não removeu
        }
        for (unsigned int i = index + 1; i < this->size_; i++) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { //Retorna elemento no índice index, −1 se índice inválido
        if (index >= this->size_) {
            return -1; // Índice inválido
        }
        return this->data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        for (unsigned int i = 0; i < this->size_; i++) {
            this->data[i] = 0;
        }
        this->size_ = 0;
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        if (this->size_ == this->capacity_) {
            this->increase_capacity();
        }
        this->data[size_++] = value;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        this->insert_at(0, value);
    }
    bool pop_back() { // Remove um elemento do ``final'' do vetor
        return this->remove_at(this->size_--);
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        return this->remove_at(0);
    }
    int front() { // Retorna o elemento do ``início'' do vetor
        if (this->size_ == 0) {
            return -1;
        }
        return this->data[0];
    }
    int back() { // Retorna o elemento do ``final'' do vetor
        if (this->size_ == 0) {
            return -1;
        }
        return this->data[this->size_--];
    }
    bool remove(int value) { // Remove value do vetor caso esteja presente
        int index = find(value);
        if (index == -1) {
            return false; // Valor não encontrado
        }
        this->remove_at(index);
    }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int index = -1;
        for (unsigned int i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                index = i;
                break;
            }
        }
        return index;
    }
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int count = 0;
        for (unsigned int i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                count++;
            }
        }
        return count;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        long long sum;
        if (this->size_ == 0){
            return 0;
        }
        for (unsigned int i = 0; i < this->size_; i++) {
            sum = sum + this->data[i];
        }
        return sum;
    }

};


#endif // __ARRAY_LIST_IFRN__