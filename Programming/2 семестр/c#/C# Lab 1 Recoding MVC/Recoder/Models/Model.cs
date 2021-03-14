using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Recoder.Models
{
    public class Model
    {
        private Encoding srcFileEncoding;
        private Encoding newFileEncoding;
        private string fileName;
        private string[] availableEncodings;

        public Encoding SrcFileEncoding { get => srcFileEncoding; set => srcFileEncoding = value; }
        public Encoding NewFileEncoding { get => newFileEncoding; set => newFileEncoding = value; }
        public string FileName { get => fileName; set => fileName = value; }
        public string[] AvailableEncodings { get => availableEncodings; }

        public Model()
        {
            this.availableEncodings = new string[] { "utf-8", "koi8-r", "windows-1251", "IBM880" };
        }
    }
}
