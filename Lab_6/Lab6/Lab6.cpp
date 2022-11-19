#include "Min_node.h"

int main()
{
    try
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout << "������� ������: " << endl;
        string str, result;
        getline(cin, str);

        map<char, string> mp = Huffman(GetFrequency(str));
        cout << "\n�������� ������������������:\n" << ShowSequence(str, mp) << endl;
        return 0;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
}