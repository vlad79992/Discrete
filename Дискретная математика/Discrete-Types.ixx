export module Discrete:Types;

import "string";
import "vector";
import "iostream";

import :ParseExpression;

export namespace discrete
{
	class Type
	{
	protected:
		std::string _name;

	public:
		virtual void PrintValue(std::ostream& os = std::cout) {}
		virtual void SetValue(const std::string& value) {}
	};
	namespace BasicTypes
	{
		class Number : Type
		{
		private:
			double value = 0.0;
		public:
			Number(const std::string& name, const std::string& value = "0.0");

			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};
		class String : Type
		{
		private:
			std::string value = "";
		public:

			String(const std::string& name, const std::string& value = "");

			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};
		class Array : Type
		{
		private:
			std::vector<Type> value;

		public:
			Array(const std::string& name, const std::string& value = "[]");
			void SetValue(const std::string& value);
			void PrintValue(std::ostream& os = std::cout);
		};
	}

	class Set : Type
	{
	protected:
		std::vector<std::vector<std::string>> value;
	public:
		Set(const std::string& name, const std::string& value = "{}");
		void SetValue(const std::string& value);
		void PrintValue(std::ostream& os = std::cout);
	};
}