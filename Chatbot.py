import random
from datetime import datetime

print("=" * 50)
print("      WELCOME TO AI CHATBOT")
print("=" * 50)
print("Type 'exit' to quit the chatbot.\n")

greetings = [
    "Hello!",
    "Hi there!",
    "Hey! Nice to meet you."
]

while True:

    user = input("You : ").lower()

    if user == "exit":
        print("Bot : Goodbye! Have a great day.")
        break

    elif "hello" in user or "hi" in user:
        print("Bot :", random.choice(greetings))

    elif "how are you" in user:
        print("Bot : I am fine. Thank you! How are you?")

    elif "your name" in user:
        print("Bot : My name is AI ChatBot.")

    elif "who made you" in user:
        print("Bot : I was created by Srushti using Python.")

    elif "python" in user:
        print("Bot : Python is a popular programming language used in AI, Data Science and Web Development.")

    elif "java" in user:
        print("Bot : Java is an object-oriented programming language.")

    elif "ai" in user or "artificial intelligence" in user:
        print("Bot : Artificial Intelligence enables machines to perform tasks that normally require human intelligence.")

    elif "time" in user:
        current_time = datetime.now().strftime("%I:%M:%S %p")
        print("Bot : Current Time =", current_time)

    elif "date" in user:
        current_date = datetime.now().strftime("%d-%m-%Y")
        print("Bot : Today's Date =", current_date)

    elif "thank you" in user or "thanks" in user:
        print("Bot : You're welcome!")

    elif "bye" in user:
        print("Bot : Bye! Have a nice day.")

    else:
        responses = [
            "Sorry, I don't understand.",
            "Can you ask something else?",
            "Please try another question.",
            "I'm still learning. Ask me something different."
        ]
        print("Bot :", random.choice(responses))