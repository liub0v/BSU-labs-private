#include <fstream>
using namespace std;

int main() {
	ifstream fin("Input.txt");
	ofstream fout("Output.txt");
	char ch_comp, ch_read;
	bool equal = true;
	int beg_pos = 0, cur_pos = 0, rep_num = 0, word_beg = 0, word_len = -1;

	fout << "Группа      Количество      Позиция" << endl;
	while (fin.get(ch_read)) {
		++cur_pos;
		if (equal) {
			++word_len;
			fin.seekg(beg_pos + word_len, ios::beg);
			fin.get(ch_comp);
			if (ch_read != ch_comp) {
				fout << "\t" << rep_num << "\t" << beg_pos << endl;
				equal = false;
				beg_pos = word_beg;
				rep_num = 0;
			}
			fin.seekg(cur_pos, ios::beg);
		}
		if (ch_read == ' ' || !fin.get(ch_read)) {
			word_len = -1;
			word_beg = cur_pos;
			if (rep_num == 0) {
				fin.seekg(beg_pos, ios::beg);
				int c = (ch_read == ' ') ? -1 : 0;
				for (int i = beg_pos; i < cur_pos + c; ++i) {
					fin.get(ch_read);
					fout << ch_read;
				}
			}
			++rep_num;
			equal = true;
		}
		fin.seekg(cur_pos, ios::beg);
	}
	fout << "\t" << rep_num << "\t" << beg_pos << endl;

	fin.close();
	fout.close();
	return 0;
}