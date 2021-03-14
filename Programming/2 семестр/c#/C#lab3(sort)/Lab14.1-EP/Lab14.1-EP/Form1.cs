using System;
using System.IO;
using System.Windows.Forms;

namespace Lab14._1_EP
{
    public partial class Form1 : Form
    {
        private MenuStrip menuMain = new MenuStrip();
        private ToolStripMenuItem menuFile = new ToolStripMenuItem();
        private ToolStripMenuItem menuFileOpen = new ToolStripMenuItem();
        private ToolStripMenuItem menuFileSaveAs = new ToolStripMenuItem();
        private ToolStripMenuItem menuFileQuit = new ToolStripMenuItem();

        string[] data;

        public Form1()
        {
            InitializeComponent();
            BuildMenu();
        }

        private void BuildMenu()
        {
            menuFile.Text = "&File";
            menuMain.Items.Add(menuFile);

            menuFileOpen.Text = "&Open file...";
            menuFile.DropDownItems.Add(menuFileOpen);
            menuFileOpen.Click += (o, s) => OnFileOpen();

            menuFileSaveAs.Text = "&Save As...";
            menuFile.DropDownItems.Add(menuFileSaveAs);
            menuFileSaveAs.Click += (o, s) => OnFileSave();

            menuFileQuit.Text = "&Quit";
            menuFile.DropDownItems.Add(menuFileQuit);
            menuFileQuit.Click += (o, s) => Application.Exit();

            Controls.Add(menuMain);
            MainMenuStrip = menuMain;
        }

        private void OnFileOpen()
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Text file (*.txt)|*.txt";
                openFileDialog.DefaultExt = "txt";
                openFileDialog.Multiselect = false;
                if (openFileDialog.ShowDialog(this) == DialogResult.OK)
                {
                    using (StreamReader dataFile = new StreamReader(openFileDialog.FileName))
                    {
                        
                        data = dataFile.ReadToEnd().Split(new char[] { '\n' });
                    }
                }
            }
        }

        private void OnFileSave()
        {
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Filter = "Text file (*.txt)|*.txt";
                saveFileDialog.DefaultExt = "txt";
                if (saveFileDialog.ShowDialog(this) == DialogResult.OK)
                {
                    if (data != null)
                    {
                        using (StreamWriter sortedFile = new StreamWriter(saveFileDialog.FileName))
                        {
                            for (int i = 0; i < data.Length; ++i)
                            {
                                sortedFile.WriteLine(data[i]);
                            }
                            sortedFile.Close();
                        }
                        MessageBox.Show("File is saved!");
                    }
                    else
                    {
                        MessageBox.Show("Please, choose a file to sort in File -> Open...");
                    }
                }
            }
        }

        void Sort(int l, int r)
        {
            if (r - l > 0)
            {
                int half = (l + r) / 2;
                Sort(l, half);
                Sort(half + 1, r);
                Merge(l, r);
            }
        }

        void Merge(int l, int r)
        {
            if (r - l > 1)
            {
                Unshuffle(l, r);
                int half = (l + r) / 2;
                Merge(l, half);
                Merge(half + 1, r);
                Shuffle(l, r);
                for (int i = l + 1; i < r; i += 2)
                {
                    Exchange(ref data[i], ref data[i + 1]);
                }
            }
            else
            {
                Exchange(ref data[l], ref data[r]);
            }
        }

        void Shuffle(int l, int r)
        {
            int half = (l + r) / 2;
            string[] tmp = new string[data.Length];
            Array.Copy(data, tmp, data.Length);
            for (int i = l, j = 0; i <= r; i += 2, ++j)
            {
                tmp[i] = data[l + j];
                tmp[i + 1] = data[half + j + 1];
            }
            data = tmp;
        }

        void Unshuffle(int l, int r)
        {
            int half = (l + r) / 2;
            string[] tmp = new string[data.Length];
            Array.Copy(data, tmp, data.Length);
            for (int i = l, j = 0; i <= r; i += 2, ++j)
            {
                tmp[l + j] = data[i];
                tmp[half + j + 1] = data[i + 1];
            }
            this.data = tmp;

        }

        void Exchange(ref string a, ref string b)
        {
            if (String.Compare(a, b) > 0)
            {
                string tmp = b;
                b = a;
                a = tmp;
            }
        }

        private void ButtonSort_Click(object sender, EventArgs e)
        {
            if (data != null)
            {
                Sort(0, data.Length - 2);
                MessageBox.Show("Succeed!\nChoose File -> Save As... to save file");
            }
            else
            {
                MessageBox.Show("Please, choose a file to sort!");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
