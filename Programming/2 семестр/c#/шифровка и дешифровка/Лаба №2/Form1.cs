using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Лаба__2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            flag_key = false;
        }

        private bool flag_key;

        private byte[] key;

        private void button2_Click(object sender, EventArgs e)
        {
            flag_key = true;
            key = new byte[128];
            Random rand = new Random();
            for (int i = 0; i < 128; i++)
                key[i] = (byte)rand.Next();
        }
        // шифрование файла
        private void button4_Click(object sender, EventArgs e)
        {
            if (!flag_key)
            {
                MessageBox.Show("Сгенерируйте ключ");
                return;
            }
            OpenFileDialog op = new OpenFileDialog();
            op.Multiselect = false;
            op.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            if (op.ShowDialog() != DialogResult.Cancel)
            {
                SaveFileDialog sv = new SaveFileDialog();
                sv.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
                sv.DefaultExt = "txt";
                sv.FileName = "Зашифрованный файл";
                if (sv.ShowDialog() != DialogResult.Cancel)
                {
                    using (FileStream file_out = new FileStream(sv.FileName, FileMode.Create))
                    {
                        using (FileStream file_from = new FileStream(op.FileName, FileMode.Open))
                        {
                            int readen_bytes = 0;
                            file_out.Write(key, 0, 128);
                            byte[] info = new byte[512];
                            while (file_from.Read(info, 0, 512) > 0)
                            {
                                int i = 0, j = 0;
                                while (i != 512)
                                {
                                    j = 0;
                                    while (j != 128)
                                    {
                                        int tmp1 = info[i], tmp2 = key[j];
                                        tmp1 = tmp1 ^ tmp2;
                                        info[i] = (byte)tmp1;
                                        i++;
                                        j++;
                                    }
                                }
                                file_out.Write(info, 0, 512);
                                readen_bytes++;
                            }
                            if (file_from.Length > readen_bytes * 512)
                            {
                                byte[] ostatok = new byte[file_from.Length - readen_bytes * 512];
                                for (int i = 0; i < file_from.Length - readen_bytes * 512; i++)
                                {
                                    int tmp1 = ostatok[i], tmp2 = key[i];
                                    tmp1 = tmp1 ^ tmp2;
                                    ostatok[i] = (byte)tmp1;
                                }
                                file_out.Write(ostatok, 0, (int)file_from.Length - readen_bytes * 512);
                            }
                        }
                        MessageBox.Show("Файл зашифрован", "Уведомление");
                    }
                }
            }
        }
        private void close_form(object sendzer, FormClosingEventArgs e)
        {
            if (MessageBox.Show("Вы точно хотите выйти?", "Вопрос", MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes)
                e.Cancel = true;
        }
        // расшифровка файла
        private void button3_Click_1(object sender, EventArgs e)
        {
            OpenFileDialog op = new OpenFileDialog();
            op.Multiselect = false;
            op.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            if (op.ShowDialog() != DialogResult.Cancel)
            {
                using (FileStream file_from = new FileStream(op.FileName, FileMode.Open))
                {
                    byte[] buf = new byte[128];
                    int readen_bytes = 0;
                    file_from.Read(buf, 0, 128);
                    List<byte> vector = new List<byte>();
                    byte[] info = new byte[512];
                    while (file_from.Read(info, 0, 512) > 0)
                    {
                        int i = 0, j = 0;
                        while (i != 512)
                        {
                            j = 0;
                            while (j != 128)
                            {
                                int tmp1 = info[i], tmp2 = buf[j];
                                tmp1 = tmp1 ^ tmp2;
                                info[i] = (byte)tmp1;
                                vector.Add(info[i]);
                                i++;
                                j++;
                            }
                        }
                        readen_bytes++;
                    }
                    if (file_from.Length > readen_bytes * 512)
                    {
                        byte[] bt = new byte[file_from.Length - readen_bytes * 512];
                        file_from.Read(bt, 0, (int)file_from.Length - readen_bytes * 512);
                        for (int i = 0; i < file_from.Length - readen_bytes * 512; i++)
                        {
                            int tmp1 = info[i], tmp2 = buf[i];
                            tmp1 = tmp1 ^ tmp2;
                            info[i] = (byte)tmp1;
                            vector.Add(info[i]);
                        }
                    }
                    string str = "";
                    byte[] mas_string = new byte[vector.Count];
                    for (int i = 0; i < vector.Count; i++)
                        mas_string[i] = vector[i];
                    str += Encoding.ASCII.GetString(mas_string);
                    MessageBox.Show("Файл расшифрован!", "Уведомление");
                    SaveFileDialog sv = new SaveFileDialog();
                    sv.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
                    sv.DefaultExt = "txt";
                    sv.FileName = "Расшифрованный файл";
                    if (sv.ShowDialog() != DialogResult.Cancel)
                        using (FileStream file_out = new FileStream(sv.FileName, FileMode.Create))
                        {
                            file_out.Write(mas_string, 0, vector.Count);
                        }
                }
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            FormClosing += close_form;
        }
    }
}
