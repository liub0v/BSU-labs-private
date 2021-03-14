using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Перекодировка
{
    public partial class Form1 : Form
    {
        private Encoding oldEncoding; // значения кодировки
        private Encoding newEncoding;
        private string nameOfFile;

        string[] encodings = new string[4]
        {
            "utf-8", "koi8-r", "windows-1251", "IBM866"
        };

        public Form1()
        {
            InitializeComponent();

            ChooseOld.Items.AddRange(encodings);
            ChooseNew.Items.AddRange(encodings);

            ChooseOld.SelectedIndex = 0;
            oldEncoding = Encoding.ASCII;
            ChooseNew.SelectedIndex = 0;
            newEncoding = Encoding.UTF8;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ChooseFile_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                nameOfFile = openFileDialog1.FileName;
            }

        }

        private void ChooseOld_SelectedIndexChanged(object sender, EventArgs e)
        {
            oldEncoding = Encoding.GetEncoding(ChooseOld.SelectedItem.ToString());
        }

        private void ChooseNew_SelectedIndexChanged(object sender, EventArgs e)
        {
            newEncoding = Encoding.GetEncoding(ChooseNew.SelectedItem.ToString());
        }

        private void RecodeFile_Click(object sender, EventArgs e)
        {
            if (oldEncoding == newEncoding)
            {
                MessageBox.Show("Вы выбрали одинаковый тип кодировки!!");
            }
            else
            {

                File.WriteAllText(nameOfFile, File.ReadAllText(nameOfFile, oldEncoding), newEncoding);

                MessageBox.Show($"Файл {nameOfFile} перекодирован из {oldEncoding.HeaderName} в {newEncoding.HeaderName}");

                ChooseNew.SelectedItem = ChooseOld.SelectedItem = newEncoding.HeaderName;
                oldEncoding = newEncoding;

            }
        }
    }
}
