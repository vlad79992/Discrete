export module Discrete:Types;

import "string";
import "vector";
import "iostream";

export namespace discrete
{
	class Type
	{
	protected:
		std::string _name;

	public:
		std::string type = "BasicType";
		virtual std::vector<std::string> toStringVec() { return {}; }
		virtual void PrintValue(std::ostream& os = std::cout) {}
		virtual void SetValue(const std::string& value) {}
	};

	namespace BasicTypes
	{
		class Number : Type
		{
		private:
			double value = 0.0;
			std::string str_value = "0.0";

		public:
			Number(const std::string& name, const std::string& value = "0.0");
			
			std::vector<std::string> toStringVec();
			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};

		class String : Type
		{
		private:
			std::string value = "";

		public:
			String(const std::string& name, const std::string& value = "");

			std::vector<std::string> toStringVec();
			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};

		class Array : Type
		{
			// [type, type]
		private:
			std::vector<Type> value;
			const std::string opening_bracket = "[",
				closing_bracket = "]";
		public:
			Array(const std::string& name, const std::string& value = "[]");

			std::vector<std::string> toStringVec();
			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};

		class Operator : Type
		{
		public:
			std::string value;
			Operator(std::string type);
		};
	}

	class Set : Type
	{
	protected:
		std::vector<std::vector<std::string>> value;

	public:
		Set(const std::string& name, const std::string& value = "{}");

		std::vector<std::string> toStringVec();
		void SetValue(const std::string& value);
		void PrintValue(std::ostream& os = std::cout);
		void Reverse();
		std::vector<std::vector<std::string>> Composition(const discrete::Set& other);
	};
}