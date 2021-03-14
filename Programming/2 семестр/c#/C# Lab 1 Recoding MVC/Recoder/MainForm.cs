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

namespace Recoder
{
    public partial class MainForm : Form
    {
        private Controllers.Controller controllor;

        public MainForm()
        {
            InitializeComponent();
        }

        public void Initialize(Controllers.Controller controllor)
        {
            this.controllor = controllor;

            ChooseNewEncoding.Items.AddRange(controllor.Model.AvailableEncodings);
            ChooseOldEncoding.Items.AddRange(controllor.Model.AvailableEncodings);

            ChooseNewEncoding.SelectedIndex = 0;
            ChooseOldEncoding.SelectedIndex = 0;

            ChooseFileButton.Text = "Выбрать файл";
            RecodeFileButton.Text = "Перекодировать";
            ChooseNewEncoding.Text = "Выбрать кодировку";
      
            labelChooseOldEncoding.Text = "Текущая кодировка";
            labelChooseNewEncoding.Text = "Новая кодировка";
        }

        private void ChooseFileButton_Click(object sender, EventArgs e)
        {
            if (ChooseFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                controllor.SetFileName(ChooseFileDialog.FileName);
                
            }
        }

        private void ChooseEncoding_SelectedIndexChanged(object sender, EventArgs e)
        {
            controllor.SetNewEncoding(ChooseNewEncoding.SelectedItem.ToString());
        }

        private void ChooseOldEncoding_SelectedIndexChanged(object sender, EventArgs e)
        {
            controllor.SetCurEncoding(ChooseOldEncoding.SelectedItem.ToString());
        }

        private void RecodeFile_Click(object sender, EventArgs e)
        {
            controllor.RecodeFile();
            if (!controllor.Errors.IsErrors)
            {
                MessageBox.Show(controllor.Log);
            }
            else
            {
                MessageBox.Show(controllor.Errors.ErrorMessage, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void labelFileName_Click(object sender, EventArgs e)
        {

        }
    }
}
