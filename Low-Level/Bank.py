import datetime
import uuid

class ValidationError(Exception):
    pass

def validate_dob(dob_str):
    try:
        dob = datetime.datetime.strptime(dob_str, "%Y-%m-%d").date()
        today = datetime.date.today()
        age = today.year - dob.year - ((today.month, today.day) < (dob.month, dob.day))
        if age < 18:
            raise ValidationError("Must be at least 18 years old.")
        return dob
    except ValueError:
        raise ValidationError("Invalid date format. Use YYYY-MM-DD.")

class Account:
    def __init__(self, account_type, pin, monthly_fee=0):
        self.account_number = str(uuid.uuid4())[:8]
        self.pin = pin
        self.balance = 0.0
        self.account_type = account_type
        self.monthly_fee = monthly_fee

    def deposit(self, amount):
        if amount <= 0:
            raise ValidationError("Deposit amount must be positive.")
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            raise ValidationError("Insufficient balance.")
        self.balance -= amount

    def charge_monthly_fee(self):
        if self.balance >= self.monthly_fee:
            self.balance -= self.monthly_fee

class Person:
    def __init__(self, name, address, dob_str, password):
        self.name = name
        self.address = address
        self.dob = validate_dob(dob_str)
        self.password = password
        self.accounts = []

    def add_account(self, account: Account):
        self.accounts.append(account)

    def get_accounts_by_type(self, account_type=None):
        if account_type:
            return [acc for acc in self.accounts if acc.account_type == account_type]
        return self.accounts

    def total_balance(self, account_type=None):
        return sum(acc.balance for acc in self.get_accounts_by_type(account_type))

class BankSystem:
    def __init__(self):
        self.customers = {}  # account_number -> (person, account)

    def create_customer(self, name, address, dob_str, password):
        person = Person(name, address, dob_str, password)
        return person

    def add_account_to_customer(self, person: Person, account_type, pin, monthly_fee=0):
        acc = Account(account_type, pin, monthly_fee)
        person.add_account(acc)
        self.customers[acc.account_number] = (person, acc)
        return acc.account_number

    def authenticate_pin(self, account_number, pin):
        person, acc = self.customers.get(account_number, (None, None))
        if acc and acc.pin == pin:
            return person, acc
        raise ValidationError("Invalid account number or PIN.")

    def authenticate_password(self, account_number, password):
        person, acc = self.customers.get(account_number, (None, None))
        if person and person.password == password:
            return person
        raise ValidationError("Invalid account number or password.")

    def deposit(self, account_number, pin, amount):
        _, acc = self.authenticate_pin(account_number, pin)
        acc.deposit(amount)

    def withdraw(self, account_number, pin, amount):
        _, acc = self.authenticate_pin(account_number, pin)
        acc.withdraw(amount)

    def transfer(self, from_acc_num, pin, to_acc_num, amount):
        _, from_acc = self.authenticate_pin(from_acc_num, pin)
        to_person, to_acc = self.customers.get(to_acc_num, (None, None))
        if not to_acc:
            raise ValidationError("Recipient account not found.")
        from_acc.withdraw(amount)
        to_acc.deposit(amount)

    def edit_customer_details(self, account_number, password, **kwargs):
        person = self.authenticate_password(account_number, password)
        for key, value in kwargs.items():
            if hasattr(person, key):
                setattr(person, key, value)

    def view_total_balance(self, account_number, password, account_type=None):
        person = self.authenticate_password(account_number, password)
        return person.total_balance(account_type)

    def apply_monthly_fees(self):
        for person, account in self.customers.values():
            account.charge_monthly_fee()
