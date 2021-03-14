using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab14_EP
{
    public partial class Form1 : Form
    {
        private MenuStrip menuMain = new MenuStrip();
        private ToolStripMenuItem menuFile = new ToolStripMenuItem();
        private ToolStripMenuItem menuFileOpen = new ToolStripMenuItem();
        private ToolStripMenuItem menuFileQuit = new ToolStripMenuItem();
        private ToolStripMenuItem menuView = new ToolStripMenuItem();
        private ToolStripMenuItem menuViewColor = new ToolStripMenuItem();
        private ToolStripMenuItem menuViewFont = new ToolStripMenuItem();
        private ToolStripMenuItem menuAbout = new ToolStripMenuItem();
        
        public Form1()
        {
            InitializeComponent();
            CenterToScreen();
            BuildMenu();
            labelQuestion.Text = "Select a file with data to show a pie chart";
            chart.Visible = false;
        }

        private void BuildMenu()
        {
            menuFile.Text = "&File";
            menuMain.Items.Add(menuFile);

            menuFileOpen.Text = "&Open file...";
            menuFile.DropDownItems.Add(menuFileOpen);
            menuFileOpen.Click += (o, s) => OnFileOpen();

            menuFileQuit.Text = "&Quit";
            menuFile.DropDownItems.Add(menuFileQuit);
            menuFileQuit.Click += (o, s) => Application.Exit();

            menuView.Text = "&View";
            menuMain.Items.Add(menuView);

            menuViewColor.Text = "&Background color...";
            menuView.DropDownItems.Add(menuViewColor);
            menuViewColor.Click += (o, s) => OnColorChoose();

            menuViewFont.Text = "&Text font...";
            menuView.DropDownItems.Add(menuViewFont);
            menuViewFont.Click += (o, s) => OnFontChoose();

            menuAbout.Text = "&About";
            menuAbout.Click += (o, s) => About();
            menuMain.Items.Add(menuAbout);

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
                    StreamReader dataFile = new StreamReader(openFileDialog.FileName);
                    ShowPieChart(dataFile);
                    dataFile.Close();
                }
            }
        }
        

        private void OnColorChoose()
        {
            ColorDialog colorDialog = new ColorDialog();
            if (colorDialog.ShowDialog(this) == DialogResult.OK)
            {
                BackColor = colorDialog.Color;
                chart.BackColor = colorDialog.Color;
            }
        }

        private void OnFontChoose()
        {
            FontDialog fontDialog = new FontDialog();
            fontDialog.ShowColor = true;
            fontDialog.MinSize = 10;
            fontDialog.MaxSize = 16;
            if (fontDialog.ShowDialog(this) == DialogResult.OK)
            {
                labelQuestion.Font = fontDialog.Font;
                labelQuestion.ForeColor = fontDialog.Color;
            }
        }

        private void About()
        {
            Form2 aboutBox = new Form2();
            aboutBox.ShowDialog();
        }

        private void ShowPieChart(StreamReader dataFile)
        {
            labelQuestion.Text = dataFile.ReadLine();
            List<int> peopleNum = new List<int>();
            List<string> itemName = new List<string>();
            while (!dataFile.EndOfStream)
            {
                string[] item = dataFile.ReadLine().Split(new char[] { ' ' });
                peopleNum.Add(int.Parse(item[0]));
                itemName.Add(item[1]);
            }
            chart.Visible = true;
            chart.Series.Clear();
            chart.Series.Add(new Series("Items")
            {
                ChartType = SeriesChartType.Pie
            });
            chart.Series["Items"].Points.DataBindXY(itemName, peopleNum);
            chart.ChartAreas[0].Area3DStyle.Enable3D = true;
        }
    }
}
