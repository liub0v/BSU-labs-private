using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Web.UI;


namespace HTML_map
{
    public partial class Form1 : Form
    {
        
        private Point RectStartPoint;
        private Point RectEndPoint;
        private Rectangle Rect = new Rectangle();
        static List<Rectangle> rectList = new List<Rectangle>();
        static List<string> nameList = new List<string>();
        static List<string> adrsList = new List<string>();
        private Brush selectionBrush = new SolidBrush(Color.FromArgb(128, 72, 145, 220));

        static readonly string strDefImage = "picture.jpeg";

        public Form1()
        {
            InitializeComponent();
            CenterToScreen();

            DomainUpDown.DomainUpDownItemCollection collection = this.domainUpDown1.Items;
            collection.Add("https://en.wikipedia.org/wiki/Triangle");
            collection.Add("https://en.wikipedia.org/wiki/Circle");
            collection.Add("https://en.wikipedia.org/wiki/Square");
            collection.Add("https://en.wikipedia.org/wiki/Rectangle");
            
            richTextBox1.Enabled = false;
            domainUpDown1.Enabled = false;
            button1.Enabled = false;
            button2.Enabled = false;
            button3.Enabled = false;
            pictureBox1.MouseMove += pictureBox1_MouseMove;
            pictureBox1.MouseDown += pictureBox1_MouseDown;
            pictureBox1.MouseUp += pictureBox1_MouseUp;
            pictureBox1.Paint += pictureBox1_Paint;
            this.domainUpDown1.Text = "...";
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            // Draw the rectangle...
            if (pictureBox1.Image != null)
            {
                if (Rect != null && Rect.Width > 0 && Rect.Height > 0)
                {
                    e.Graphics.FillRectangle(selectionBrush, Rect);
                }
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            bool check = true;
                RectEndPoint = e.Location;

            if (RectStartPoint.X - RectEndPoint.X > 0)
            {
                int Temp = RectStartPoint.X;
                RectStartPoint.X = RectEndPoint.X;
                RectEndPoint.X = Temp;
            }
            if (RectStartPoint.Y - RectEndPoint.Y > 0)
            {
                int Temp = RectStartPoint.Y;
                RectStartPoint.Y = RectEndPoint.Y;
                RectEndPoint.Y = Temp;
            }

            Rect.Location = new Point(
             Math.Min(RectStartPoint.X, RectEndPoint.X),
             Math.Min(RectStartPoint.Y, RectEndPoint.Y));
            Rect.Size = new Size(
                    Math.Abs(RectStartPoint.X - RectEndPoint.X),
                    Math.Abs(RectStartPoint.Y - RectEndPoint.Y));
            for (int i = 0; i < rectList.Count; ++i)
            {
                if (RectStartPoint.Y > (rectList[i].Y + rectList[i].Height) || RectEndPoint.Y < rectList[i].Y
                   || RectEndPoint.X < rectList[i].X || RectStartPoint.X > (rectList[i].X + rectList[i].Width))
                {
                  
                }
                else {  MessageBox.Show(
                       "Error: selected area intersects previously selected areas!",
                       "Warning message",
                       MessageBoxButtons.OK,
                       MessageBoxIcon.Error);
                check = false; break;
                }
            }
            if (check == true)
            {
                rectList.Add(Rect);
                richTextBox1.Enabled = true;
                button1.Enabled = true;
                domainUpDown1.Enabled = true;
                button2.Enabled = true;
            }
        }
 

        void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            RectStartPoint = e.Location;
            richTextBox1.Text = null;
            richTextBox1.Enabled = false;
            domainUpDown1.Text = null;
            domainUpDown1.Enabled = false;
            button1.Enabled = false;
            button2.Enabled = false;
            //Invalidate();
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button != MouseButtons.Left)
                return;
            Point tempEndPoint = e.Location;
            Rect.Location = new Point(
                Math.Min(RectStartPoint.X, tempEndPoint.X),
                Math.Min(RectStartPoint.Y, tempEndPoint.Y));
            Rect.Size = new Size(
                Math.Abs(RectStartPoint.X - tempEndPoint.X),
                Math.Abs(RectStartPoint.Y - tempEndPoint.Y));
            pictureBox1.Invalidate();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileimg = ChooseFile(
                        "Выберете изображение",
                        "Jpeg изображения (*.jpeg)|*.jpeg", "jpeg",
                        "*.jpeg", strDefImage);

            string ChooseFile(
            string title, string filter,
            string defExt, string fname,
            string defFile)
            {
                using (OpenFileDialog openFileDialog1 =
                        new OpenFileDialog())
                {
                    openFileDialog1.Title = title;
                    openFileDialog1.InitialDirectory = ".";
                    openFileDialog1.Filter = filter;
                    openFileDialog1.FilterIndex = 0;
                    openFileDialog1.DefaultExt = defExt;
                    openFileDialog1.FileName = fname;
                    openFileDialog1.RestoreDirectory = true;
                    openFileDialog1.Multiselect = false;
                    if (openFileDialog1.ShowDialog() ==
                            DialogResult.OK)
                    {
                        return openFileDialog1.FileName;
                    }
                }
                MessageBox.Show(
                       "Файл не найден ",
                       "Warning message",
                       MessageBoxButtons.OK,
                       MessageBoxIcon.Error);
                return defFile;
            }

            pictureBox1.Image = Image.FromFile(fileimg, true);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        
        static string GetElements()
        {
            StringWriter stringWriter = new StringWriter();
            
            using (HtmlTextWriter writer = new HtmlTextWriter(stringWriter))
            {
                
                writer.RenderBeginTag("!DOCTYPE html");
                writer.RenderBeginTag(HtmlTextWriterTag.Html); // 1
                writer.RenderBeginTag(HtmlTextWriterTag.Head);
                writer.RenderBeginTag(HtmlTextWriterTag.Title);
                writer.Write("Геометрические фигуры");
                writer.RenderEndTag();
                writer.AddAttribute(HtmlTextWriterAttribute.Rel, "stylesheet");
                writer.AddAttribute(HtmlTextWriterAttribute.Type, "text/css");
                writer.AddAttribute(HtmlTextWriterAttribute.Href, "styles.css");
                writer.RenderBeginTag(HtmlTextWriterTag.Link);
                writer.RenderEndTag();
                writer.RenderBeginTag(HtmlTextWriterTag.Body); // 2
                writer.RenderBeginTag("p"); //
                writer.RenderEndTag();
                writer.WriteLine();
                writer.AddAttribute(HtmlTextWriterAttribute.Src, "picture.jpeg");
                writer.AddAttribute(HtmlTextWriterAttribute.Width, "774");
                writer.AddAttribute(HtmlTextWriterAttribute.Height, "572");
                writer.AddAttribute(HtmlTextWriterAttribute.Alt, "Geometry");
                writer.AddAttribute(HtmlTextWriterAttribute.Usemap, "#geometrymap");
                writer.RenderBeginTag(HtmlTextWriterTag.Img); // 4
               // writer.RenderEndTag();
                writer.WriteLine();

                writer.AddAttribute(HtmlTextWriterAttribute.Name, "geometrymap");
                writer.RenderBeginTag(HtmlTextWriterTag.Map); // 5
                
                for (int i = 0; i < nameList.Count; ++i)
                {
                    writer.AddAttribute(HtmlTextWriterAttribute.Shape, "rect");
                    string coords = (rectList[i].X + "," + rectList[i].Y + "," + 
                        (rectList[i].X+rectList[i].Width) + "," + (rectList[i].Y+rectList[i].Height)).ToString();
                    writer.AddAttribute(HtmlTextWriterAttribute.Coords, coords);

                    writer.AddAttribute(HtmlTextWriterAttribute.Alt, nameList[i]);
                    writer.AddAttribute(HtmlTextWriterAttribute.Href, adrsList[i]);
                    writer.AddAttribute(HtmlTextWriterAttribute.Target, "_blank");
                    writer.RenderBeginTag(HtmlTextWriterTag.Area);
                    writer.WriteLine();
                }
                writer.Write("<area shape="); writer.Write("rect"); writer.Write(" coords=");
                writer.Write("0,0,774,572"); writer.Write(" nohref"); writer.Write(" alt=");
                writer.Write("NoHref"); writer.Write(">");
                writer.WriteLine();


                writer.RenderEndTag();
                writer.RenderEndTag();
                writer.RenderEndTag();
                writer.RenderEndTag(); // 2
                writer.RenderEndTag(); // 1

            }

            return stringWriter.ToString();
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                string path_html = "", path_txt = "";
                FolderBrowserDialog FBD = new FolderBrowserDialog();
                if (FBD.ShowDialog() == DialogResult.OK)
                {
                  path_html = FBD.SelectedPath + "\\Geometry.html";
                  path_txt = FBD.SelectedPath + "\\Markup.txt";
                }
                using (var writer = new StreamWriter(path_html))
                {
                    writer.WriteLine(GetElements());
                }
                using (var writer = new StreamWriter(path_txt))
                {
                    writer.WriteLine(GetElements());
                }
                MessageBox.Show("HTML-map was saved!");
                button3.Enabled = true;
            }
            catch (SystemException err)
            {
                MessageBox.Show(err.Message);
            }

        }


        private void button1_Click(object sender, EventArgs e)
        {
            nameList.Add(richTextBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            adrsList.Add(domainUpDown1.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"C:\Users\User\source\repos\c#\C#(lab5)\laba5(map)\HTML-map\HTML-map\bin\Debug\Geometry.html");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
