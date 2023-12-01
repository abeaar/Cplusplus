#include <iostream>
#include <malloc.h>
#define max 5
#define True 1
#define False 0
using std::cout;
typedef float typeinfo;
typedef struct typequeue
{
    int depan, belakang;
    typeinfo elemen[max];
};
struct typequeue queue;
void buatqueue();
void cetakqueue();
void enqueue(float IB);
void dequeue();
int queuekosong();
int queuepenuh();
int main()
{
    buatqueue();
    enqueue(12);
    enqueue(78);
    enqueue(5);
    enqueue(34);
    cetakqueue();
    cout << "\n\n";
    dequeue();
    dequeue();
    cetakqueue();
    cout << "\n\n";
    enqueue(89);
    enqueue(11);
    cetakqueue();
}

void buatqueue()
{
    queue.depan = 1;
    queue.belakang = 1;
}

int queuekosong()
{
    if (queue.depan == queue.belakang)
        return (True);
    else
        return (False);
}
int queuepenuh()
{
    int next_belakang;
    if (queue.belakang == max)
        next_belakang = 1;
    else
        next_belakang = queue.belakang + 1;
    if (queue.depan == next_belakang)
        return (True);
    else
        return (False);
}

void enqueue(float IB)
{
    if (queuepenuh())
        cout << "queue overflow\n";
    else
    {
        if (queue.belakang == max)
            queue.belakang = 1;
        else
            queue.belakang++;
        queue.elemen[queue.belakang] = IB;
    }
}

void dequeue()
{
    typeinfo ID;
    if (queuekosong())
        cout << "queue underflow\n";
    else
    {
        ID = queue.elemen[queue.depan + 1];
        if (queue.depan == max)
            queue.depan = 1;
        else
            queue.depan++;
    }
}

void cetakqueue()
{
    int i;
    if (queue.depan == queue.belakang)
        cout << "Queue kosong !";
    else
    {
        if (queue.depan < queue.belakang)
        {
            i = queue.depan + 1;
            while (i <= queue.belakang)
            {
                cout << " " << queue.elemen[i];
                i++;
            }
        }
        else
        {
            for (i = queue.depan + 1; i <= max; i++)
                cout << " " << queue.elemen[i];
            for (i = 1; i <= queue.belakang; i++)
                cout << " " << queue.elemen[i];
        }
    }
}
