# main.py

from models import Quiz
from quiz_manager import load_questions, take_quiz


def main():

    print("========================================")
    print("       ONLINE QUIZ AND EVALUATION")
    print("========================================")

    student_name = input("Enter student name: ").strip()

    if student_name == "":
        print("Student name cannot be empty.")
        return

    questions = load_questions()

    if len(questions) == 0:
        print("No questions available.")
        return

    quiz = Quiz("Python Programming Quiz")

    for question in questions:
        quiz.add_question(question)

    print(f"\nQuiz Title : {quiz.title}")
    print(f"Total Questions : {len(quiz.questions)}")

    input("\nPress Enter to start the quiz...")

    score, total, report = take_quiz(
        student_name,
        quiz.questions
    )

    percentage = (score / total) * 100

    print("\n========================================")
    print("             QUIZ COMPLETED")
    print("========================================")

    print(f"Student     : {student_name}")
    print(f"Score       : {score}/{total}")
    print(f"Percentage  : {percentage:.2f}%")

    if percentage >= 80:
        print("Performance : Excellent")
    elif percentage >= 60:
        print("Performance : Good")
    elif percentage >= 40:
        print("Performance : Average")
    else:
        print("Performance : Needs Improvement")

    if report:
        print("\nReport generated successfully:")
        print(report)

    print("\nThank you for taking the quiz!")


if __name__ == "__main__":
    main()
