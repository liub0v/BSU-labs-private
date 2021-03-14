using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public Bitmap CutImage(Bitmap src, Rectangle rect,int w,int h)
        {

            Bitmap bmp = new Bitmap(src.Width/w, src.Height/h); //создаем битмап

            Graphics g = Graphics.FromImage(bmp);

            g.DrawImage(src, 0, 0, rect, GraphicsUnit.Pixel); //перерисовываем с источника по координатам

            return bmp;
        }
        static int h, w;
        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = temp;

        }
        Image temp;
        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Jpg file (*.jpg)|*.jpg";
                openFileDialog.DefaultExt = "jpg";
                openFileDialog.Multiselect = false;
                if (openFileDialog.ShowDialog(this) == DialogResult.OK)
                {
                    using (StreamReader dataFile = new StreamReader(openFileDialog.FileName))
                    {

                       temp = Image.FromFile(openFileDialog.FileName);
                    }
                }

            }

        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string strw, strh;
            strw = textBox1.Text;
            strh = textBox2.Text;
            h = Convert.ToUInt16(strw);
            w = Convert.ToUInt16(strh);
            /*Image temp = Image.FromFile("123.jpg");*/// pictureBox1.Image;// берем картинку или 
            Bitmap src = new Bitmap(temp, temp.Width, temp.Height);
            // Задаем нужную область вырезания (отсчет с верхнего левого угла)

            int count = 1;
            string[] filename = new string[w * h];

            for (int j = 1; j <= h; j++)
                for (int i = 1; i <= w; i++)
                {
                    Rectangle rect;
                    //Rectangle rect = new Rectangle(new Point(0, 0), new Size(pictureBox1.Width / w, pictureBox1.Height / h));

                    rect = new Rectangle(new Point((i - 1) * temp.Width / w, ((j - 1)) * temp.Height / h), new Size(temp.Width / w, temp.Height / h));
                    Bitmap CuttedImage = CutImage(src, rect, w, h);
  
                    filename[count - 1] = count.ToString();
                    CuttedImage.Save(filename[count - 1] + ".gif", System.Drawing.Imaging.ImageFormat.Gif);
                    count++;

                }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

       
    }
    
}
