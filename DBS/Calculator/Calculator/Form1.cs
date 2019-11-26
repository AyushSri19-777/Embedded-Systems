using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        String op = "null";
        String n1 = "";
        String n2 = "";

        private void zeroButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("0");
            if (op != "null")
                n2 = n2 + "0";
        }

        private void oneButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("1");
            if (op != "null")
                n2 = n2 + "1";
        }

        private void twoButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("2");
            if (op != "null")
                n2 = n2 + "2";
        }

        private void threeButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("3");
            if (op != "null")
                n2 = n2 + "3";
        }

        private void fourButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("4");
            if (op != "null")
                n2 = n2 + "4";
        }

        private void fiveButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("5");
            if (op != "null")
                n2 = n2 + "5";
        }

        private void sixButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("6");
            if (op != "null")
                n2 = n2 + "6";
        }

        private void sevenButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("7");
            if (op != "null")
                n2 = n2 + "7";
        }

        private void eightButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("8");
            if (op != "null")
                n2 = n2 + "8";
        }

        private void nineButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("9");
            if (op != "null")
                n2 = n2 + "9";
        }

        private void decimalButton_Click(object sender, EventArgs e)
        {
            textBox1.AppendText(".");
            if (op != "null")
                n2 = n2 + ".";
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void percentButton_Click(object sender, EventArgs e)
        {
            double num = double.Parse(textBox1.Text);
            num = num/100;
            textBox1.Text = num.ToString(); 
        }

        private void subtractButton_Click(object sender, EventArgs e)
        {
            n1 = textBox1.Text;
            op = "-";
            textBox1.AppendText("-");
        }

        private void sumButton_Click(object sender, EventArgs e)
        {
            n1 = textBox1.Text;
            op = "+";
            textBox1.AppendText("+");
        }

        private void multiplyButton_Click(object sender, EventArgs e)
        {
            n1 = textBox1.Text;
            op = "*";
            textBox1.AppendText("*");
        }

        private void divideButton_Click(object sender, EventArgs e)
        {
            n1 = textBox1.Text;
            op = "/";
            textBox1.AppendText("/");
        }

        private void squareButton_Click(object sender, EventArgs e)
        {
            double num = double.Parse(textBox1.Text);
            num = num*num;
            textBox1.Text = num.ToString();
        }

        private void inverseButton_Click(object sender, EventArgs e)
        {
            double num = double.Parse(textBox1.Text);
            num = 1/num;
            textBox1.Text = num.ToString();
        }

        private void computeButton_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(n1);
            double num2 = double.Parse(n2);
            double res = 0.0;
            if (op == "+")
                res = num1 + num2;
            else if (op == "-")
                res = num1 - num2;
            else if (op == "*")
                res = num1 * num2;
            else if (op == "/")
                res = num1 / num2;

            textBox1.Text = res.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void sinButton_Click(object sender, EventArgs e)
        {
            double rad = double.Parse(textBox1.Text);
            rad = Math.Sin(rad);
            textBox1.Text = rad.ToString();
        }

        private void cosButton_Click(object sender, EventArgs e)
        {
            double rad = double.Parse(textBox1.Text);
            rad = Math.Cos(rad);
            textBox1.Text = rad.ToString();
        }

        private void tanButton_Click(object sender, EventArgs e)
        {
            double rad = double.Parse(textBox1.Text);
            rad = Math.Tan(rad);
            textBox1.Text = rad.ToString();
        }

        private void logButton_Click(object sender, EventArgs e)
        {
            double numb = double.Parse(textBox1.Text);
            numb = Math.Log(numb);
            textBox1.Text = numb.ToString();
        }
    }
}
