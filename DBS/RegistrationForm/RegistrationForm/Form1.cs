using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RegistrationForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                if (CSEradioButton.Checked == true || ITradioButton.Checked == true || CCEradioButton.Checked == true)
                {
                    submitButton.Visible = true;
                }
            }
            else
            {
                submitButton.Visible = false;
                MessageBox.Show("Answer every field!");
            }
        }

        private void submitButton_Click(object sender, EventArgs e)
        {
            String name = textBox1.Text;
            String email = textBox2.Text;
            String phoneNumber = textBox3.Text;
            String stream = "";

            if (CSEradioButton.Checked == true)
                stream = "CSE";
            else if (ITradioButton.Checked == true)
                stream = "IT";
            else if (CCEradioButton.Checked == true)
                stream = "CCE";

            String date = dateTimePicker1.Value.ToString();

            String grade = comboBox1.SelectedItem.ToString();

            String msg = "Hi "+name+".\nDOB: "+date+"\nPhone Number: "+phoneNumber+"\nApplied Stream: "+stream+"\n12th Grade: "+grade;

            MessageBox.Show(msg);

        }

        private void CSEradioButton_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
