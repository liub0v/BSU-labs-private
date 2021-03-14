namespace Recoder
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ChooseFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.ChooseFileButton = new System.Windows.Forms.Button();
            this.ChooseNewEncoding = new System.Windows.Forms.ComboBox();
            this.RecodeFileButton = new System.Windows.Forms.Button();
            this.ChooseOldEncoding = new System.Windows.Forms.ComboBox();
            this.labelChooseOldEncoding = new System.Windows.Forms.Label();
            this.labelChooseNewEncoding = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ChooseFileDialog
            // 
            this.ChooseFileDialog.FileName = "ChooseFileDialog";
            // 
            // ChooseFileButton
            // 
            this.ChooseFileButton.Location = new System.Drawing.Point(48, 13);
            this.ChooseFileButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.ChooseFileButton.Name = "ChooseFileButton";
            this.ChooseFileButton.Size = new System.Drawing.Size(129, 28);
            this.ChooseFileButton.TabIndex = 0;
            this.ChooseFileButton.Text = "button1";
            this.ChooseFileButton.UseVisualStyleBackColor = true;
            this.ChooseFileButton.Click += new System.EventHandler(this.ChooseFileButton_Click);
            // 
            // ChooseNewEncoding
            // 
            this.ChooseNewEncoding.FormattingEnabled = true;
            this.ChooseNewEncoding.Location = new System.Drawing.Point(35, 68);
            this.ChooseNewEncoding.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.ChooseNewEncoding.Name = "ChooseNewEncoding";
            this.ChooseNewEncoding.Size = new System.Drawing.Size(160, 24);
            this.ChooseNewEncoding.TabIndex = 1;
            this.ChooseNewEncoding.SelectedIndexChanged += new System.EventHandler(this.ChooseEncoding_SelectedIndexChanged);
            // 
            // RecodeFileButton
            // 
            this.RecodeFileButton.Location = new System.Drawing.Point(48, 149);
            this.RecodeFileButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.RecodeFileButton.Name = "RecodeFileButton";
            this.RecodeFileButton.Size = new System.Drawing.Size(140, 28);
            this.RecodeFileButton.TabIndex = 2;
            this.RecodeFileButton.Text = "button1";
            this.RecodeFileButton.UseVisualStyleBackColor = true;
            this.RecodeFileButton.Click += new System.EventHandler(this.RecodeFile_Click);
            // 
            // ChooseOldEncoding
            // 
            this.ChooseOldEncoding.FormattingEnabled = true;
            this.ChooseOldEncoding.Location = new System.Drawing.Point(34, 117);
            this.ChooseOldEncoding.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.ChooseOldEncoding.Name = "ChooseOldEncoding";
            this.ChooseOldEncoding.Size = new System.Drawing.Size(160, 24);
            this.ChooseOldEncoding.TabIndex = 3;
            this.ChooseOldEncoding.SelectedIndexChanged += new System.EventHandler(this.ChooseOldEncoding_SelectedIndexChanged);
            // 
            // labelChooseOldEncoding
            // 
            this.labelChooseOldEncoding.AutoSize = true;
            this.labelChooseOldEncoding.CausesValidation = false;
            this.labelChooseOldEncoding.Location = new System.Drawing.Point(32, 96);
            this.labelChooseOldEncoding.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelChooseOldEncoding.Name = "labelChooseOldEncoding";
            this.labelChooseOldEncoding.Size = new System.Drawing.Size(46, 17);
            this.labelChooseOldEncoding.TabIndex = 5;
            this.labelChooseOldEncoding.Text = "label1";
            // 
            // labelChooseNewEncoding
            // 
            this.labelChooseNewEncoding.AutoSize = true;
            this.labelChooseNewEncoding.CausesValidation = false;
            this.labelChooseNewEncoding.Location = new System.Drawing.Point(31, 45);
            this.labelChooseNewEncoding.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelChooseNewEncoding.Name = "labelChooseNewEncoding";
            this.labelChooseNewEncoding.Size = new System.Drawing.Size(46, 17);
            this.labelChooseNewEncoding.TabIndex = 6;
            this.labelChooseNewEncoding.Text = "label1";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(242, 200);
            this.Controls.Add(this.labelChooseNewEncoding);
            this.Controls.Add(this.labelChooseOldEncoding);
            this.Controls.Add(this.ChooseOldEncoding);
            this.Controls.Add(this.RecodeFileButton);
            this.Controls.Add(this.ChooseNewEncoding);
            this.Controls.Add(this.ChooseFileButton);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog ChooseFileDialog;
        private System.Windows.Forms.Button ChooseFileButton;
        private System.Windows.Forms.ComboBox ChooseNewEncoding;
        private System.Windows.Forms.Button RecodeFileButton;
        private System.Windows.Forms.ComboBox ChooseOldEncoding;
        private System.Windows.Forms.Label labelChooseOldEncoding;
        private System.Windows.Forms.Label labelChooseNewEncoding;
    }
}