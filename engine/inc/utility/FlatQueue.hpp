/**
 *  @file    FlatQueue.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/23/2021
 *  @version 1.0
 */

#ifndef NOVUM_ENGINE_FLAT_QUEUE_HPP
#define NOVUM_ENGINE_FLAT_QUEUE_HPP

#include <vector>
#include <cstddef>

namespace novum_engine::utility
{
	template <typename T>
	class [[maybe_unused]] FlatQueue
	{
	public:
		using container_type = std::vector<T>;
		using value_type = T;
		using size_type = std::size_t;
		using reference = T&;
		using const_reference = T const&;

		explicit FlatQueue(size_type size = block_size) noexcept : m_current_size(0), m_head(0), m_tail(0)
		{
			m_flat_queue.resize(size);
		}

		[[maybe_unused]] FlatQueue(std::initializer_list<T> list) noexcept : m_current_size(0), m_head(0),
																	 m_tail(list.size())
		{
			m_flat_queue.resize(list.size());
			std::copy(list.begin(), list.end(), m_flat_queue.begin());
		}

		FlatQueue(FlatQueue const& rhs) noexcept = delete;
		FlatQueue& operator=(FlatQueue const& rhs) noexcept = delete;

		FlatQueue(FlatQueue&& rhs) noexcept = delete;
		FlatQueue& operator=(FlatQueue&& rhs) noexcept = delete;

		~FlatQueue() noexcept = default;

		/* Element access */
		reference front() { return m_flat_queue[m_head]; }
		[[nodiscard]] const_reference front() const { return m_flat_queue[m_head]; }

		[[maybe_unused]] reference back() { return m_flat_queue[m_tail]; }

		[[maybe_unused]] [[nodiscard]] const_reference back() const { return m_flat_queue[m_tail]; }

		/* Capacity */
		[[nodiscard]] bool empty() const { return m_current_size == 0; }
		[[nodiscard]] size_type size() const { return m_current_size; }

		[[maybe_unused]] [[nodiscard]] size_type capacity() const { return m_flat_queue.size(); }

		/* Modifiers */
		[[maybe_unused]] void push(const_reference value)
		{
			if (m_current_size == m_flat_queue.size())
				m_flat_queue.resize(m_flat_queue.size() + block_size);

			m_flat_queue[m_tail] = value;
			m_tail = (m_tail + 1) % m_flat_queue.size();

			m_current_size++;
		}

		[[maybe_unused]] void push(value_type&& value)
		{
			if (m_current_size == m_flat_queue.size())
				m_flat_queue.resize(m_flat_queue.size() + block_size);

			m_flat_queue[m_tail] = std::move(value);
			m_tail = (m_tail + 1) % m_flat_queue.size();

			m_current_size++;
		}

		[[maybe_unused]] void pop()
		{
			if (!empty())
			{
				m_head = (m_head + 1) % m_flat_queue.size();
				m_current_size--;

				if (m_current_size == m_flat_queue.size() - block_size)
					m_flat_queue.resize(m_flat_queue.size() - block_size);
			}
		}

	private:
		container_type m_flat_queue;

		size_type m_current_size;

		size_type m_head;
		size_type m_tail;

		static constexpr std::size_t block_size = 10;
	};
}

#endif /* NOVUM_ENGINE_FLAT_QUEUE_HPP */
