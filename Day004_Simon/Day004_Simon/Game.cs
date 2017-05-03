using System;
using System.Collections;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Day004_Simon {
  class Game {
    public Game() {
      for (int x = 0; x < 10; x++)
        addNewPress();
    }

    public ArrayList buttonSequence = new ArrayList();
    Random r = new Random(DateTime.Now.Millisecond);

    public void addNewPress() {
      buttonSequence.Add((buttonEnum)r.Next(0, 3));
    }

    public void playSequence(MainForm form, SoundManager sm) {
      foreach (buttonEnum x in buttonSequence) {
        switch (x) {
          case (buttonEnum.GREEN):
            sm.greenSound.Play();
            form.updateUI(Color.Green);
            break;
          case (buttonEnum.RED):
            sm.redSound.Play();
            form.updateUI(Color.Red);
            break;
          case (buttonEnum.YELLOW):
            sm.yellowSound.Play();
            form.updateUI(Color.Yellow);
            break;
          case (buttonEnum.BLUE):
            sm.blueSound.Play();
            form.updateUI(Color.Blue);
            break;
        }
        Thread.Sleep(500);
      }
    }
  }
}
