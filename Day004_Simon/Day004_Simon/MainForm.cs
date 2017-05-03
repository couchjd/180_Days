using System;
using System.Collections;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Media;
using System.IO;
using System.Timers;

namespace Day004_Simon {
  enum buttonEnum { GREEN, RED, YELLOW, BLUE, NONE };

  public partial class MainForm : Form {
    SoundManager sm;
    Game game;
    public MainForm() {
      game = new Game();
      sm = new SoundManager();
      InitializeComponent();
      this.Text = "Simon";
    }

    public void updateUI(Color newColor) {
      Button pressedButton = greenButton;
      if (newColor == Color.Green)
        pressedButton = greenButton;
      if (newColor == Color.Red)
        pressedButton = redButton;
      if (newColor == Color.Yellow)
        pressedButton = yellowButton;
      if (newColor == Color.Blue)
        pressedButton = blueButton;

      Color temp = pressedButton.BackColor;
      pressedButton.BackColor = newColor;
      pressedButton.Invalidate();
      pressedButton.Update();
      pressedButton.Refresh();
      Application.DoEvents();
      Thread.Sleep(200);
      pressedButton.BackColor = temp;
      pressedButton.Invalidate();
      pressedButton.Update();
      pressedButton.Refresh();
      Application.DoEvents();
    }

    public void simulateButtonPress(Color newColor) {
      sm.greenSound.Play();
      updateUI(Color.Green);
    }

    private void greenButton_Click(object sender, EventArgs e) {
      sm.greenSound.Play();
    }

    private void redButton_Click(object sender, EventArgs e) {
      sm.redSound.Play();
    }

    private void yellowButton_Click(object sender, EventArgs e) {
      sm.yellowSound.Play();
    }

    private void blueButton_Click(object sender, EventArgs e) {
      sm.blueSound.Play();
    }

    private void playButton_Click(object sender, EventArgs e) {

    }

    private void playbackButton_Click(object sender, EventArgs e) {
      game.playSequence(this, sm);
    }
  }
}
