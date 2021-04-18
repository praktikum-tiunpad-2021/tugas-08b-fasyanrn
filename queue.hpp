#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  int priority;
  Element* next;
  Element (T data, int priority){
    this -> data = data;
    this -> priority = priority;
    this -> next = nullptr;
  }
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> baru;
  baru.head = nullptr;
  baru.tail = nullptr;
  return baru;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> baru = new Element<T> (value, priority);
  if(q.head == nullptr){
    q.head = baru;
    q.tail = baru;
  } else{
    ElementPtr<T> help = q.head;
    ElementPtr<T> help2 = nullptr;
    while (help -> priority >= priority && help -> next != nullptr){
      help2 = help;
      help = help -> next;
    }
    if (help == q.head && help -> priority < priority){
      baru -> next = help;
      q.head = baru;
    } else if (help == q.tail && help -> priority > priority){
      help -> next = baru;
      q.tail = baru;
    } else {
      help2 -> next = baru;
      baru -> next = help;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head -> data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> delElement;
  if(q.head == nullptr && q.tail == nullptr){
    delElement = nullptr;
  } else if(q.head -> next == nullptr){
    delElement = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else{
    delElement = q.head;
    q.head = q.head->next;
    delElement -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
