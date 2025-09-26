import { useState } from 'react'
import './App.css'

function App() {
  const tabs = ['Salas', 'Pistas', 'Suspeitos', 'Ajuda'] as const
  const [activeTab, setActiveTab] = useState<typeof tabs[number]>('Salas')
  const [showModal, setShowModal] = useState(false)
  const [toast, setToast] = useState<{ kind: 'success' | 'warning' | 'danger' | 'info'; text: string } | null>(null)

  const svgFor = (t: typeof tabs[number]) => {
    switch (t) {
      case 'Salas':
        return (<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round"><rect x="3" y="4" width="6" height="6"/><rect x="15" y="4" width="6" height="6"/><rect x="9" y="14" width="6" height="6"/></svg>)
      case 'Pistas':
        return (<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round"><circle cx="11" cy="11" r="7"/><line x1="20" y1="20" x2="16" y2="16"/></svg>)
      case 'Suspeitos':
        return (<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round"><circle cx="12" cy="8" r="4"/><path d="M4 20c0-4 4-6 8-6s8 2 8 6"/></svg>)
      case 'Ajuda':
        return (<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round"><circle cx="12" cy="12" r="9"/><path d="M9.5 9a3 3 0 0 1 5 1c0 2-3 2.5-3 4"/><line x1="12" y1="17" x2="12" y2="17"/></svg>)
      default:
        return null
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
            {svgFor(t)}
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
