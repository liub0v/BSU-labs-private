using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Recoder.Models;

namespace Recoder.Controllers
{
    public class ControllerErrors
    {
        private bool isErrors = false;
        private string errorMessage = "";

        public bool IsErrors { get => isErrors; }
        public string ErrorMessage { get => errorMessage; }

        public void reset()
        {
            isErrors = false;
            errorMessage = "";
        }

        public void set(string name)
        {
            isErrors = true;
            errorMessage = name;
        }
    }
    public class Controller
    {
        private MainForm view;
        private Models.Model model;
        private ControllerErrors errors;
        private string log = "";
        public Controller(MainForm view)
        {
            errors = new ControllerErrors();
            this.Model = new Models.Model();
            this.view = view;

            this.view.Initialize(this);
        }

        public void SetNewEncoding(string name)
        {
            errors.reset();
            model.NewFileEncoding = Encoding.GetEncoding(name);
        }
        public void SetCurEncoding(string name)
        {
            errors.reset();
            model.SrcFileEncoding = Encoding.GetEncoding(name);
        }

        public void RecodeFile()
        {
            errors.reset();
            if (File.Exists(model.FileName))
            {
                File.WriteAllText(model.FileName, File.ReadAllText(model.FileName, model.SrcFileEncoding), model.NewFileEncoding);

                log = $"Файл {model.FileName} перекодирован из {model.SrcFileEncoding.HeaderName} в {model.NewFileEncoding.HeaderName}";
            }
            else
            {
                errors.set("Ничего не выбрано");
            }
        }

        public void SetFileName(string name)
        {
            model.FileName = name;
        }

        public MainForm View { get => view; }
        public Models.Model Model { get => model; set => model = value; }
        public ControllerErrors Errors { get => errors; }
        public string Log { get => log; }
    }
}
