namespace Day004_Simon
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
      this.greenButton = new System.Windows.Forms.Button();
      this.redButton = new System.Windows.Forms.Button();
      this.yellowButton = new System.Windows.Forms.Button();
      this.blueButton = new System.Windows.Forms.Button();
      this.playbackButton = new System.Windows.Forms.Button();
      this.playButton = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // greenButton
      // 
      this.greenButton.BackColor = System.Drawing.Color.DarkGreen;
      this.greenButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.greenButton.Location = new System.Drawing.Point(40, 11);
      this.greenButton.Name = "greenButton";
      this.greenButton.Size = new System.Drawing.Size(96, 96);
      this.greenButton.TabIndex = 0;
      this.greenButton.Text = "green";
      this.greenButton.UseVisualStyleBackColor = false;
      this.greenButton.Click += new System.EventHandler(this.greenButton_Click);
      // 
      // redButton
      // 
      this.redButton.BackColor = System.Drawing.Color.DarkRed;
      this.redButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.redButton.Location = new System.Drawing.Point(142, 11);
      this.redButton.Name = "redButton";
      this.redButton.Size = new System.Drawing.Size(96, 96);
      this.redButton.TabIndex = 1;
      this.redButton.Text = "red";
      this.redButton.UseVisualStyleBackColor = false;
      this.redButton.Click += new System.EventHandler(this.redButton_Click);
      // 
      // yellowButton
      // 
      this.yellowButton.BackColor = System.Drawing.Color.DarkGoldenrod;
      this.yellowButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.yellowButton.Location = new System.Drawing.Point(40, 113);
      this.yellowButton.Name = "yellowButton";
      this.yellowButton.Size = new System.Drawing.Size(96, 96);
      this.yellowButton.TabIndex = 2;
      this.yellowButton.Text = "yellow";
      this.yellowButton.UseVisualStyleBackColor = false;
      this.yellowButton.Click += new System.EventHandler(this.yellowButton_Click);
      // 
      // blueButton
      // 
      this.blueButton.BackColor = System.Drawing.Color.DarkBlue;
      this.blueButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.blueButton.Location = new System.Drawing.Point(142, 113);
      this.blueButton.Name = "blueButton";
      this.blueButton.Size = new System.Drawing.Size(96, 96);
      this.blueButton.TabIndex = 3;
      this.blueButton.Text = "blue";
      this.blueButton.UseVisualStyleBackColor = false;
      this.blueButton.Click += new System.EventHandler(this.blueButton_Click);
      // 
      // playbackButton
      // 
      this.playbackButton.Location = new System.Drawing.Point(142, 223);
      this.playbackButton.Name = "playbackButton";
      this.playbackButton.Size = new System.Drawing.Size(101, 23);
      this.playbackButton.TabIndex = 4;
      this.playbackButton.Text = "Play Sequence";
      this.playbackButton.UseVisualStyleBackColor = true;
      this.playbackButton.Click += new System.EventHandler(this.playbackButton_Click);
      // 
      // playButton
      // 
      this.playButton.Location = new System.Drawing.Point(35, 223);
      this.playButton.Name = "playButton";
      this.playButton.Size = new System.Drawing.Size(101, 23);
      this.playButton.TabIndex = 5;
      this.playButton.Text = "Play";
      this.playButton.UseVisualStyleBackColor = true;
      this.playButton.Click += new System.EventHandler(this.playButton_Click);
      // 
      // MainForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(284, 261);
      this.Controls.Add(this.playButton);
      this.Controls.Add(this.playbackButton);
      this.Controls.Add(this.blueButton);
      this.Controls.Add(this.yellowButton);
      this.Controls.Add(this.redButton);
      this.Controls.Add(this.greenButton);
      this.Name = "MainForm";
      this.Text = "Form1";
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.Button greenButton;
    private System.Windows.Forms.Button redButton;
    private System.Windows.Forms.Button yellowButton;
    private System.Windows.Forms.Button blueButton;
    private System.Windows.Forms.Button playbackButton;
    private System.Windows.Forms.Button playButton;
  }
}

