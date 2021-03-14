namespace Перекодировка
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.ChooseFile = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.RecodeFile = new System.Windows.Forms.Button();
            this.ChooseOld = new System.Windows.Forms.DomainUpDown();
            this.ChooseNew = new System.Windows.Forms.DomainUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ChooseFile
            // 
            this.ChooseFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ChooseFile.Location = new System.Drawing.Point(12, 12);
            this.ChooseFile.Name = "ChooseFile";
            this.ChooseFile.Size = new System.Drawing.Size(70, 140);
            this.ChooseFile.TabIndex = 0;
            this.ChooseFile.Text = "file";
            this.ChooseFile.UseVisualStyleBackColor = true;
            this.ChooseFile.Click += new System.EventHandler(this.ChooseFile_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // RecodeFile
            // 
            this.RecodeFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RecodeFile.Location = new System.Drawing.Point(100, 117);
            this.RecodeFile.Name = "RecodeFile";
            this.RecodeFile.Size = new System.Drawing.Size(124, 35);
            this.RecodeFile.TabIndex = 2;
            this.RecodeFile.Text = "recode";
            this.RecodeFile.UseVisualStyleBackColor = true;
            this.RecodeFile.Click += new System.EventHandler(this.RecodeFile_Click);
            // 
            // ChooseOld
            // 
            this.ChooseOld.Location = new System.Drawing.Point(100, 29);
            this.ChooseOld.Name = "ChooseOld";
            this.ChooseOld.ReadOnly = true;
            this.ChooseOld.Size = new System.Drawing.Size(195, 22);
            this.ChooseOld.TabIndex = 3;
            this.ChooseOld.Text = "ChooseOldEncoding";
            this.ChooseOld.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ChooseOld.Wrap = true;
            this.ChooseOld.SelectedItemChanged += new System.EventHandler(this.ChooseOld_SelectedIndexChanged);
            // 
            // ChooseNew
            // 
            this.ChooseNew.Location = new System.Drawing.Point(99, 80);
            this.ChooseNew.Name = "ChooseNew";
            this.ChooseNew.ReadOnly = true;
            this.ChooseNew.Size = new System.Drawing.Size(196, 22);
            this.ChooseNew.TabIndex = 4;
            this.ChooseNew.Text = "ChooseNewEncoding";
            this.ChooseNew.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ChooseNew.Wrap = true;
            this.ChooseNew.SelectedItemChanged += new System.EventHandler(this.ChooseNew_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Old English Text MT", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(96, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(179, 21);
            this.label1.TabIndex = 5;
            this.label1.Text = "старая кодировка";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Old English Text MT", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(672, 157);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 21);
            this.label2.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(96, 54);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(169, 21);
            this.label3.TabIndex = 7;
            this.label3.Text = "новая кодировка";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(343, 169);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ChooseNew);
            this.Controls.Add(this.ChooseOld);
            this.Controls.Add(this.RecodeFile);
            this.Controls.Add(this.ChooseFile);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.Text = "перекодировка";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button ChooseFile;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button RecodeFile;
        private System.Windows.Forms.DomainUpDown ChooseOld;
        private System.Windows.Forms.DomainUpDown ChooseNew;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

