# models.py

class Question:
    def __init__(self, question_id, question_text, options, correct_answer):
        self.question_id = question_id
        self.question_text = question_text
        self.options = options
        self.correct_answer = correct_answer


class StudentResponse:
    def __init__(self, student_name, question_id, answer):
        self.student_name = student_name
        self.question_id = question_id
        self.answer = answer


class Quiz:
    def __init__(self, title):
        self.title = title
        self.questions = []

    def add_question(self, question):
        self.questions.append(question)

    def display_questions(self):
        for question in self.questions:
            print(f"\nQ{question.question_id}. {question.question_text}")

            for option in question.options:
                print(option)
