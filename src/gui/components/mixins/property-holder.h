#pragma once
#include <string>
#include <variant>
#include <unordered_map>
#define ALLOWED_PROPERTY_TYPES int, float, std::string

class PropertyHolder
{
private:
	struct SWidgetProperty
	{
		PropertyHolder* m_holder;
		std::string m_key;
	
		SWidgetProperty(PropertyHolder* holder, std::string key)
		{
			m_holder = holder;
			m_key = key;
		}
		
		template<typename T>
		operator T() { return m_holder->get<T>(m_key); }
		
		template<typename T>
		bool operator ==(const T& value) { return m_holder->get<T>(m_key) == value; }
		
		template<typename T>
		void operator =(const T& value) { return m_holder->set<T>(m_key, value); }
	};

public:	
	SWidgetProperty operator[] (std::string key)
	{
		return SWidgetProperty(this, key);
	}

private:
	template<typename T>
	T get(std::string key) { return std::get<T>(m_properties[key]); }
	
	template<typename T>
	void set(std::string key, T value) { m_properties[key] = value; }

private:
	std::unordered_map<std::string, std::variant<ALLOWED_PROPERTY_TYPES>> m_properties;
};

