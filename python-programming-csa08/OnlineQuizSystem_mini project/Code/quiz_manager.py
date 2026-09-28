# quiz_manager.py

import os
from models import Question, StudentResponse


QUESTION_FILE = "questions.txt"
RESPONSE_FILE = "responses.txt"
LOG_FILE = "quiz_logs.txt"
REPORT_FOLDER = "reports"


def load_questions():
    questions = []

    try:
        with open(QUESTION_FILE, "r") as file:

            for line in file:
                line = line.strip()

                if not line:
                    continue

                data = line.split("|")

                question_id = int(data[0])
                question_text = data[1]

                options = [
                    "A. " + data[2],
                    "B. " + data[3],
                    "C. " + data[4],
                    "D. " + data[5]
                ]

                correct_answer = data[6].upper()

                question = Question(
                    question_id,
                    question_text,
                    options,
                    correct_answer
                )

                questions.append(question)

    except FileNotFoundError:
        print("Error: questions.txt file not found.")

    except Exception as e:
        print("Error while loading questions:", e)

    return questions


def save_response(response):
    try:
        with open(RESPONSE_FILE, "a") as file:
            file.write(
                f"{response.student_name}|"
                f"{response.question_id}|"
                f"{response.answer}\n"
            )

    except Exception as e:
        print("Error saving response:", e)


def log_attempt(student_name, score, total):
    try:
        with open(LOG_FILE, "a") as file:

            percentage = (score / total) * 100

            file.write(
                f"Student: {student_name} | "
                f"Score: {score}/{total} | "
                f"Percentage: {percentage:.2f}%\n"
            )

    except Exception as e:
        print("Error writing log:", e)


def evaluate_answer(student_answer, correct_answer):

    if student_answer == "":
        return "Missing"

    if student_answer not in ["A", "B", "C", "D"]:
        return "Invalid"

    if student_answer == correct_answer:
        return "Correct"

    return "Wrong"


def generate_report(student_name, results, score, total):

    if not os.path.exists(REPORT_FOLDER):
        os.makedirs(REPORT_FOLDER)

    percentage = (score / total) * 100

    if percentage >= 80:
        performance = "Excellent"
    elif percentage >= 60:
        performance = "Good"
    elif percentage >= 40:
        performance = "Average"
    else:
        performance = "Needs Improvement"

    filename = (
        REPORT_FOLDER + "/" +
        student_name.replace(" ", "_") +
        "_report.txt"
    )

    try:
        with open(filename, "w") as file:

            file.write("====================================\n")
            file.write("       ONLINE QUIZ RESULT REPORT\n")
            file.write("====================================\n\n")

            file.write(f"Student Name : {student_name}\n")
            file.write(f"Score        : {score}/{total}\n")
            file.write(f"Percentage   : {percentage:.2f}%\n")
            file.write(f"Performance  : {performance}\n\n")

            file.write("Question-wise Result\n")
            file.write("------------------------------------\n")

            for result in results:
                file.write(
                    f"Q{result['question_id']} : "
                    f"Your Answer = {result['answer']} | "
                    f"Correct Answer = {result['correct']} | "
                    f"Result = {result['status']}\n"
                )

            file.write("\n====================================\n")

        return filename

    except Exception as e:
        print("Error generating report:", e)
        return None


def take_quiz(student_name, questions):

    responses = []
    results = []
    score = 0

    print("\n====================================")
    print("           ONLINE QUIZ")
    print("====================================")

    for question in questions:

        print(f"\nQ{question.question_id}. {question.question_text}")

        for option in question.options:
            print(option)

        while True:

            answer = input(
                "Enter your answer (A/B/C/D): "
            ).strip().upper()

            if answer == "":
                print("No answer entered. Marked as Missing.")
                break

            if answer not in ["A", "B", "C", "D"]:
                print(
                    "Invalid response! "
                    "Please enter A, B, C or D."
                )
                continue

            break

        response = StudentResponse(
            student_name,
            question.question_id,
            answer
        )

        responses.append(response)

        status = evaluate_answer(
            answer,
            question.correct_answer
        )

        if status == "Correct":
            score += 1

        results.append({
            "question_id": question.question_id,
            "answer": answer if answer else "Not Answered",
            "correct": question.correct_answer,
            "status": status
        })

        save_response(response)

    total = len(questions)

    log_attempt(
        student_name,
        score,
        total
    )

    report = generate_report(
        student_name,
        results,
        score,
        total
    )

    return score, total, report
