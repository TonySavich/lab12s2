#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>


class Teacher;

class Student {
public:
	Student(const std::string& name) {
		m_name = name;
		std::cout << " Student create" << std::endl;
	}
	~Student() {
		std::cout << " Student delete" << std::endl;
	}



	std::string NameS() { return m_name; }
	std::shared_ptr<Student> GetT() { m_teacher; }

	friend void studie(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);

private:
	std::string m_name;
	std::shared_ptr<Teacher> m_teacher;
};


class Teacher {
public:
	Teacher(const std::string& name) {
		m_name = name;
		m_i = -1;
		std::cout << " Teacher create" << std::endl;
	}
	~Teacher() {
		std::cout << " Teacher delete" << std::endl;
	}
	std::string NameT() { return m_name; }
	std::shared_ptr<Student> GetS() {
		return (m_student[m_i]);
	}
	int all() {
		return(m_i);

	}

	void allstudent() {
		for (int i = 0; i < m_i; i++) {
			std::cout << m_student[m_i];
		}
	}

	void addstudent() {
		m_i = m_i + 1;
		std::cout << " Student add" << std::endl;
	}

	friend void studie(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);

private:
	std::string m_name;
	int m_i;
	std::shared_ptr<Student> m_student[10];

};

void studie(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S) {
	T->addstudent();
	S->m_teacher = T;
	T->GetS() = S;
	std::cout << T->m_name << " teach " << S->m_name << std::endl;
}



int main()
{
	std::shared_ptr<Student> student = std::make_shared<Student>("Damian");
	std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Bruce");
	std::shared_ptr<Student> student2 = std::make_shared<Student>("Jason");
	studie(teacher, student);
	studie(teacher, student2);
}
