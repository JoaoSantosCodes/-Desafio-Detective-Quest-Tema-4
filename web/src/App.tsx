import { useState } from 'react'
import './App.css'

function App() {
  const tabs = ['Salas', 'Pistas', 'Suspeitos', 'Ajuda'] as const
  const [activeTab, setActiveTab] = useState<typeof tabs[number]>('Salas')
  const [showModal, setShowModal] = useState(false)
  const [toast, setToast] = useState<{ kind: 'success' | 'warning' | 'danger' | 'info'; text: string } | null>(null)

  const iconFor = (t: typeof tabs[number]) => {
    const name = t.toLowerCase()
    switch (name) {
      case 'salas': return '/icons/icon-salas.svg'
      case 'pistas': return '/icons/icon-pistas.svg'
      case 'suspeitos': return '/icons/icon-suspeitos.svg'
      case 'ajuda': return '/icons/icon-ajuda.svg'
      default: return undefined
    }
  }

  return (
    <div className="app">
      <header style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: '16px' }}>
        <h1 style={{ fontSize: '24px', lineHeight: '32px', margin: 0 }}>Detective Quest</h1>
        <div style={{ display: 'flex', gap: '8px' }}>
          <button className="btn btn--primary" onClick={() => setShowModal(true)}>Adicionar</button>
          <button className="btn btn--ghost" onClick={() => setToast({ kind: 'info', text: 'Dica rápida exibida!' })}>Dica</button>
        </div>
      </header>

      <nav className="tabs" role="tablist" aria-label="Navegação Principal">
        {tabs.map((t) => (
          <button
            key={t}
            role="tab"
            aria-selected={activeTab === t}
            className={`tab ${activeTab === t ? 'tab--active' : ''}`}
            onClick={() => setActiveTab(t)}
          >
            {/* Inline <img> for simplicity; could be optimized with SVG symbols later */}
            {iconFor(t) && <img src={iconFor(t)} alt="" aria-hidden="true" style={{ width: 20, height: 20 }} />}
            {t}
          </button>
        ))}
      </nav>

      {activeTab === 'Salas' && (
        <section>
          <div style={{ display: 'flex', gap: '12px', marginBottom: '12px' }}>
            <input className="input" placeholder="Buscar sala" aria-label="Buscar sala" />
            <button className="btn btn--secondary">Filtrar</button>
          </div>
          <div className="list">
            {["Entrada", "Corredor", "Biblioteca", "Laboratório"].map((item, i) => (
              <div key={i} className="list-item" role="button" tabIndex={0}>{item}</div>
            ))}
          </div>
        </section>
      )}

      {activeTab === 'Pistas' && (
        <section>
          <div style={{ display: 'flex', gap: '12px', marginBottom: '12px' }}>
            <input className="input" placeholder="Buscar pista" aria-label="Buscar pista" />
            <button className="btn btn--secondary">Filtrar</button>
          </div>
          <div className="list">
            {["Pegada", "Fibra têxtil", "Registro de acesso"].map((item, i) => (
              <div key={i} className="list-item" role="button" tabIndex={0}>{item}</div>
            ))}
          </div>
        </section>
      )}

      {activeTab === 'Suspeitos' && (
        <section>
          <div style={{ display: 'flex', gap: '12px', marginBottom: '12px' }}>
            <input className="input" placeholder="Buscar suspeito" aria-label="Buscar suspeito" />
            <button className="btn btn--secondary">Filtrar</button>
          </div>
          <div className="list">
            {["Ana","Bruno","Carla"].map((item, i) => (
              <div key={i} className="list-item" role="button" tabIndex={0}>{item}</div>
            ))}
          </div>
        </section>
      )}

      {activeTab === 'Ajuda' && (
        <section>
          <div className="list" style={{ maxWidth: 640 }}>
            <div className="list-item">F1: Abrir Ajuda</div>
            <div className="list-item">Tab: Navegar entre itens</div>
            <div className="list-item">Enter: Confirmar ação</div>
            <div className="list-item">Esc: Fechar modal</div>
          </div>
        </section>
      )}

      {showModal && (
        <div className="modal-backdrop" role="dialog" aria-modal="true">
          <div className="modal">
            <h2 style={{ margin: 0 }}>Adicionar item</h2>
            <p>Preencha os dados do novo item.</p>
            <input className="input" placeholder="Nome" aria-label="Nome" />
            <div style={{ display: 'flex', gap: '8px', justifyContent: 'flex-end' }}>
              <button className="btn btn--ghost" onClick={() => setShowModal(false)}>Cancelar</button>
              <button className="btn btn--primary" onClick={() => { setShowModal(false); setToast({ kind: 'success', text: 'Item adicionado!' }) }}>Salvar</button>
            </div>
          </div>
        </div>
      )}

      {toast && (
        <div className={`toast toast--${toast.kind}`} role="status">
          {toast.text}
        </div>
      )}
    </div>
  )
}

export default App
